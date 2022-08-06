import pandas as pd
import pulp


"""
We'll explore the scheduling of 2 factories, both of them had 2 costs:
1. Fixed Costs - costs incurred while the factory is running
2. Variable Costs - cost per unit of production

We'are going to introduce a third cost, Start up cost. This will be a cost incurred by turning on the machines at one of the factories.
In this time, out start-up cost will be:
1. Factory A : $  20,000
2. Factory B : $ 400,000

Activity is started by reminding ourselves of the input data
"""
factories = pd.read_csv('factory_variables.csv', index_col=['Month', 'Factory'])
demand = pd.read_csv('monthly_demand.csv', index_col=['Month'])

""" We will begin by defining our decision variables, 
    we have an additional binary variable for switching on the factory"""
production = pulp.LpVariable.dicts("production", ((month, factory) for month, factory in factories.index), lowBound=0, cat='Integer')  # Production
factory_status = pulp.LpVariable.dicts("factory_status", ((month, factory) for month, factory in factories.index), cat='Binary')  # Factory Status // On or Off
switch_on = pulp.LpVariable.dicts("switch_on", ((month, factory) for month, factory in factories.index), lowBound=0, cat='Integer')  # Factory Switch // On or Off

""" We instantiate our model and define our objective function,
    including start-up costs"""
model = pulp.LpProblem("Cost minimizing scheduling problem", pulp.LpMinimize)  # initialize the model

# Select index on factory A or B
factory_A_index = [tpl for tpl in factories.index if tpl[1] == 'A']
factory_B_index = [tpl for tpl in factories.index if tpl[1] == 'B']

# Define objective function
model += pulp.lpSum( [production[m, f] * factories.loc[(m, f), 'Variable_Costs'] for m, f in factories.index] + [factory_status[m, f] * factories.loc[(m, f), 'Fixed_Costs'] for m, f in factories.index] + [switch_on[m, f] * 20000 for m, f in factory_A_index] + [switch_on[m, f] * 400000 for m, f in factory_B_index])

# We begin to build up our constrain, start with production in any month must be equal to demand
months = demand.index
for month in months:
    model += production[(month, 'A')] + production[(month, 'B')] == demand.loc[month, 'Demand']

# Production in any month must be between minimum and maximum capacity, or zero
for month, factory in factories.index:
    min_production = factories.loc[(month, factory), 'Min_Capacity']
    max_production = factories.loc[(month, factory), 'Max_Capacity']
    model += production[(month, factory)] >= min_production * factory_status[month, factory]
    model += production[(month, factory)] <= max_production * factory_status[month, factory]

# Factory B is off in May
model += factory_status[5, 'B'] == 0
model += production[5, 'B'] == 0

""" But, now we want to add in our constrains for switching on.
    A factory switches on if:
    >> It is off in the previous month (m - 1)
    >> AND, it on in the current month (m)
    As we don't know, if the factory is on before month 0, 
    we'll assume that the factory has switched on if it is on in month 1"""
for month, factory in factories.index:
    # In month 1, if the factory is on, we assume it turned on
    if month == 1:
        model += switch_on[month, factory] == factory_status[month, factory]
    # In other months, if the factory is on in the current month AND off in the previous month, switch on = 1
    else:
        model += switch_on[month, factory] >= factory_status[month, factory] - factory_status[month - 1, factory]
        model += switch_on[month, factory] <= 1 - factory_status[month - 1, factory]
        model += switch_on[month, factory] <= factory_status[month, factory]

""" To solve our mathematical model
    Using Linear Programming with Python PuLP"""
model.solve()

""" To print out our calculation result
    IT WILL MORE ADVANCE IF RESULT CAN BE PRINTED IN .csv FILE"""
output = []
for month, factory in production:
    var_output = {
        'Month': month,
        'Factory': factory,
        'Production': production[(month, factory)],
        'Factory Status': factory_status[(month, factory)],
        'Switch On': switch_on[(month, factory)]
    }
    output.append(var_output)
output_df = pd.DataFrame.from_records(output).sort_values(['Month', 'Factory'])
output_df.set_index(['Month', 'Factory'], inplace=True)

print(factories)
print(demand)
print(pulp.LpStatus[model.status])
print(output_df)

""" RESULTS & DISCUSSION
    Interestingly, we see that it now makes economic sense to keep factory B on after it turns off in month 5 up until month 12.
    Previously, we had the case that it was not economic to run factory B in month 10, but as there is now a significant cost to 
    switching off and back on, the factory runs through month 10 at its lowest capacity (20,000 units)                          """