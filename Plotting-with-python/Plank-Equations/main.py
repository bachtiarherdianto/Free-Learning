import matplotlib.pyplot as plt, numpy as np

h, c, k = 6.626e-34, 3.0e+8, 1.38e-23       # initialize the constants

def planckFunct(wav, T):
    alpha = 2.0 * h * c**2
    beta = h * c / (wav * k * T)
    return alpha / ((wav**5) * (np.exp(beta) - 1.0))

def wavelengths():
    ''' generate x-axis in increments from 1 nanometer to micrometer in 1 nanometer
        increments, starting at 1 nanometer to avoid wave = 0, which would result 
        in division by zero '''
    return np.arange(1e-9, 3e-6, 1e-9)


def BlackBodySpectrum(wave, temperature):
    plt.style.use('dark_background')

    # generating spectrum
    alpha = planckFunct(wave, temperature[0])
    beta = planckFunct(wave, temperature[1])
    gamma = planckFunct(wave, temperature[2])
    delta = planckFunct(wave, temperature[3])

    # plotting the spectrum
    plt.plot(wave*1e9, alpha, 'r-', label='T= {0}'.format(temperature[0]))
    plt.plot(wave*1e9, beta, 'g-', label='T= {0}'.format(temperature[1]))
    plt.plot(wave*1e9, gamma, 'b-', label='T= {0}'.format(temperature[2]))
    plt.plot(wave*1e9, delta, 'w-', label='T= {0}'.format(temperature[3]))

    # setting the graph
    plt.xlabel(r'$\omega [\mathcal{Hz}]$')
    plt.ylabel(r'$\rho (\omega; \mathcal{T}) [\mathcal{Jm}^{-3}]$')
    plt.text(2000, 2e13, r'$B_{\nu }(\nu ,T)={\frac {2h\nu ^{3}}{c^{2}}}{\frac {1}{e^{h\nu /(k_{\mathrm {B} }T)}-1}}$')
    plt.legend(loc='best')
    plt.show()

intensity = [4000, 5000, 6000, 7000]

BlackBodySpectrum(wavelengths(), intensity)
