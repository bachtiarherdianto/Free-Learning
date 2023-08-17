# first neural network with keras tutorial
# source: https://machinelearningmastery.com/tutorial-first-neural-network-python-keras/
from numpy import loadtxt
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense

# load the dataset
dataset = loadtxt("main.csv", delimiter=',')

# split into input (X) and output (y) variables
X = dataset[:,0:8]
y = dataset[:,8]

# define the keras model
model = Sequential()
model.add(Dense(12, input_shape=(8,), activation="relu"))
model.add(Dense(8, activation="relu"))
model.add(Dense(1, activation="sigmoid"))

# compile the keras model
model.compile(loss="binary_crossentropy", optimizer="adam", metrics=["accuracy"])

# fit the keras model on the dataset
model.fit(X, y, epochs=150, batch_size=10)

# evaluate the keras model
loss_val, accuracy_val = model.evaluate(X, y)
print("Accuracy: %.2f" % (accuracy_val*100))

"""
D:\python main.py

2023-08-17 08:17:55.198474: I tensorflow/core/platform/cpu_feature_guard.cc:182] This TensorFlow binary is optimized to use available CPU instructions in performance-critical operations.
To enable the following instructions: SSE SSE2 SSE3 SSE4.1 SSE4.2 AVX AVX2 FMA, in other operations, rebuild TensorFlow with the appropriate compiler flags.
Epoch 1/150
77/77 [==============================] - 2s 3ms/step - loss: 1.8356 - accuracy: 0.4935
Epoch 2/150
77/77 [==============================] - 0s 3ms/step - loss: 1.0286 - accuracy: 0.5508
Epoch 3/150
77/77 [==============================] - 0s 3ms/step - loss: 0.8882 - accuracy: 0.5846
Epoch 4/150
77/77 [==============================] - 0s 3ms/step - loss: 0.7980 - accuracy: 0.6146
Epoch 5/150
77/77 [==============================] - 0s 3ms/step - loss: 0.7609 - accuracy: 0.6341
Epoch 6/150
77/77 [==============================] - 0s 3ms/step - loss: 0.7322 - accuracy: 0.6562
Epoch 7/150
77/77 [==============================] - 0s 3ms/step - loss: 0.7140 - accuracy: 0.6510
Epoch 8/150
77/77 [==============================] - 0s 3ms/step - loss: 0.6909 - accuracy: 0.6589
Epoch 9/150
77/77 [==============================] - 0s 3ms/step - loss: 0.6813 - accuracy: 0.6615
Epoch 10/150
77/77 [==============================] - 0s 3ms/step - loss: 0.6856 - accuracy: 0.6680
Epoch 11/150
77/77 [==============================] - 0s 3ms/step - loss: 0.6639 - accuracy: 0.6615
Epoch 12/150
77/77 [==============================] - 0s 3ms/step - loss: 0.6516 - accuracy: 0.6745
Epoch 13/150
77/77 [==============================] - 0s 3ms/step - loss: 0.6428 - accuracy: 0.6693
Epoch 14/150
77/77 [==============================] - 0s 3ms/step - loss: 0.6370 - accuracy: 0.6732
Epoch 15/150
77/77 [==============================] - 0s 3ms/step - loss: 0.6329 - accuracy: 0.6562
Epoch 16/150
77/77 [==============================] - 0s 3ms/step - loss: 0.6252 - accuracy: 0.6693
Epoch 17/150
77/77 [==============================] - 0s 4ms/step - loss: 0.6198 - accuracy: 0.6784
Epoch 18/150
77/77 [==============================] - 1s 7ms/step - loss: 0.6164 - accuracy: 0.6745
Epoch 19/150
77/77 [==============================] - 0s 3ms/step - loss: 0.6185 - accuracy: 0.6966
Epoch 20/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5972 - accuracy: 0.7018
Epoch 21/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5982 - accuracy: 0.6966
Epoch 22/150
77/77 [==============================] - 0s 3ms/step - loss: 0.6146 - accuracy: 0.6849
Epoch 23/150
77/77 [==============================] - 0s 3ms/step - loss: 0.6049 - accuracy: 0.7057
Epoch 24/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5953 - accuracy: 0.6914
Epoch 25/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5828 - accuracy: 0.7057
Epoch 26/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5845 - accuracy: 0.7096
Epoch 27/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5896 - accuracy: 0.6901
Epoch 28/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5871 - accuracy: 0.7044
Epoch 29/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5842 - accuracy: 0.7122
Epoch 30/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5856 - accuracy: 0.7057
Epoch 31/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5717 - accuracy: 0.7057
Epoch 32/150
77/77 [==============================] - 0s 4ms/step - loss: 0.5763 - accuracy: 0.7031
Epoch 33/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5773 - accuracy: 0.7174
Epoch 34/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5778 - accuracy: 0.7214
Epoch 35/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5733 - accuracy: 0.7148
Epoch 36/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5640 - accuracy: 0.7266
Epoch 37/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5747 - accuracy: 0.7096
Epoch 38/150
77/77 [==============================] - 0s 4ms/step - loss: 0.5692 - accuracy: 0.7109
Epoch 39/150
77/77 [==============================] - 0s 4ms/step - loss: 0.5696 - accuracy: 0.7018
Epoch 40/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5678 - accuracy: 0.7201
Epoch 41/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5762 - accuracy: 0.7083
Epoch 42/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5604 - accuracy: 0.7253
Epoch 43/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5615 - accuracy: 0.7227
Epoch 44/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5575 - accuracy: 0.7174
Epoch 45/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5755 - accuracy: 0.7083
Epoch 46/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5829 - accuracy: 0.7057
Epoch 47/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5654 - accuracy: 0.7253
Epoch 48/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5590 - accuracy: 0.7253
Epoch 49/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5633 - accuracy: 0.7174
Epoch 50/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5533 - accuracy: 0.7148
Epoch 51/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5483 - accuracy: 0.7318
Epoch 52/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5535 - accuracy: 0.7357
Epoch 53/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5492 - accuracy: 0.7266
Epoch 54/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5474 - accuracy: 0.7396
Epoch 55/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5568 - accuracy: 0.7214
Epoch 56/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5517 - accuracy: 0.7201
Epoch 57/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5486 - accuracy: 0.7253
Epoch 58/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5598 - accuracy: 0.7214
Epoch 59/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5602 - accuracy: 0.7214
Epoch 60/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5437 - accuracy: 0.7279
Epoch 61/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5472 - accuracy: 0.7357
Epoch 62/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5447 - accuracy: 0.7448
Epoch 63/150
77/77 [==============================] - 0s 4ms/step - loss: 0.5413 - accuracy: 0.7266
Epoch 64/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5397 - accuracy: 0.7292
Epoch 65/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5568 - accuracy: 0.7174
Epoch 66/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5477 - accuracy: 0.7422
Epoch 67/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5326 - accuracy: 0.7396
Epoch 68/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5358 - accuracy: 0.7357
Epoch 69/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5496 - accuracy: 0.7370
Epoch 70/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5588 - accuracy: 0.7188
Epoch 71/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5462 - accuracy: 0.7331
Epoch 72/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5476 - accuracy: 0.7383
Epoch 73/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5351 - accuracy: 0.7370
Epoch 74/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5329 - accuracy: 0.7331
Epoch 75/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5372 - accuracy: 0.7331
Epoch 76/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5327 - accuracy: 0.7344
Epoch 77/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5294 - accuracy: 0.7526
Epoch 78/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5283 - accuracy: 0.7318
Epoch 79/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5300 - accuracy: 0.7383
Epoch 80/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5256 - accuracy: 0.7461
Epoch 81/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5402 - accuracy: 0.7461
Epoch 82/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5348 - accuracy: 0.7331
Epoch 83/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5236 - accuracy: 0.7474
Epoch 84/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5281 - accuracy: 0.7409
Epoch 85/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5311 - accuracy: 0.7474
Epoch 86/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5198 - accuracy: 0.7552
Epoch 87/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5294 - accuracy: 0.7500
Epoch 88/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5317 - accuracy: 0.7357
Epoch 89/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5278 - accuracy: 0.7487
Epoch 90/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5256 - accuracy: 0.7318
Epoch 91/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5173 - accuracy: 0.7552
Epoch 92/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5366 - accuracy: 0.7305
Epoch 93/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5147 - accuracy: 0.7526
Epoch 94/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5162 - accuracy: 0.7617
Epoch 95/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5260 - accuracy: 0.7331
Epoch 96/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5123 - accuracy: 0.7461
Epoch 97/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5239 - accuracy: 0.7422
Epoch 98/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5153 - accuracy: 0.7487
Epoch 99/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5160 - accuracy: 0.7500
Epoch 100/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5286 - accuracy: 0.7422
Epoch 101/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5237 - accuracy: 0.7526
Epoch 102/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5222 - accuracy: 0.7318
Epoch 103/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5247 - accuracy: 0.7435
Epoch 104/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5151 - accuracy: 0.7604
Epoch 105/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5111 - accuracy: 0.7487
Epoch 106/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5135 - accuracy: 0.7487
Epoch 107/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5117 - accuracy: 0.7435
Epoch 108/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5236 - accuracy: 0.7526
Epoch 109/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5125 - accuracy: 0.7461
Epoch 110/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5147 - accuracy: 0.7474
Epoch 111/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5096 - accuracy: 0.7396
Epoch 112/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5191 - accuracy: 0.7409
Epoch 113/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5096 - accuracy: 0.7552
Epoch 114/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5243 - accuracy: 0.7500
Epoch 115/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5160 - accuracy: 0.7487
Epoch 116/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5211 - accuracy: 0.7383
Epoch 117/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5209 - accuracy: 0.7591
Epoch 118/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5090 - accuracy: 0.7604
Epoch 119/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5093 - accuracy: 0.7409
Epoch 120/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5021 - accuracy: 0.7526
Epoch 121/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5064 - accuracy: 0.7461
Epoch 122/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5088 - accuracy: 0.7500
Epoch 123/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5013 - accuracy: 0.7578
Epoch 124/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5071 - accuracy: 0.7539
Epoch 125/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5044 - accuracy: 0.7578
Epoch 126/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5106 - accuracy: 0.7630
Epoch 127/150
77/77 [==============================] - 0s 3ms/step - loss: 0.4948 - accuracy: 0.7656
Epoch 128/150
77/77 [==============================] - 0s 3ms/step - loss: 0.4972 - accuracy: 0.7721
Epoch 129/150
77/77 [==============================] - 0s 3ms/step - loss: 0.4988 - accuracy: 0.7643
Epoch 130/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5039 - accuracy: 0.7435
Epoch 131/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5009 - accuracy: 0.7552
Epoch 132/150
77/77 [==============================] - 0s 3ms/step - loss: 0.4933 - accuracy: 0.7695
Epoch 133/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5034 - accuracy: 0.7682
Epoch 134/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5149 - accuracy: 0.7630
Epoch 135/150
77/77 [==============================] - 0s 3ms/step - loss: 0.4926 - accuracy: 0.7630
Epoch 136/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5017 - accuracy: 0.7630
Epoch 137/150
77/77 [==============================] - 0s 3ms/step - loss: 0.4983 - accuracy: 0.7669
Epoch 138/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5003 - accuracy: 0.7539
Epoch 139/150
77/77 [==============================] - 0s 3ms/step - loss: 0.4970 - accuracy: 0.7578
Epoch 140/150
77/77 [==============================] - 0s 4ms/step - loss: 0.5019 - accuracy: 0.7474
Epoch 141/150
77/77 [==============================] - 0s 4ms/step - loss: 0.4960 - accuracy: 0.7591
Epoch 142/150
77/77 [==============================] - 0s 4ms/step - loss: 0.4967 - accuracy: 0.7656
Epoch 143/150
77/77 [==============================] - 0s 4ms/step - loss: 0.4954 - accuracy: 0.7617
Epoch 144/150
77/77 [==============================] - 0s 4ms/step - loss: 0.4915 - accuracy: 0.7604
Epoch 145/150
77/77 [==============================] - 1s 6ms/step - loss: 0.5190 - accuracy: 0.7344
Epoch 146/150
77/77 [==============================] - 0s 3ms/step - loss: 0.4923 - accuracy: 0.7578
Epoch 147/150
77/77 [==============================] - 0s 5ms/step - loss: 0.4884 - accuracy: 0.7669
Epoch 148/150
77/77 [==============================] - 0s 4ms/step - loss: 0.4974 - accuracy: 0.7526
Epoch 149/150
77/77 [==============================] - 0s 3ms/step - loss: 0.5115 - accuracy: 0.7500
Epoch 150/150
77/77 [==============================] - 0s 3ms/step - loss: 0.4979 - accuracy: 0.7682
24/24 [==============================] - 0s 3ms/step - loss: 0.5037 - accuracy: 0.7682
"""
