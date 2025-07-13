import numpy as np
import cv2 as cv
from matplotlib import pyplot as plt

img = cv.imread('mammogram_digital_Xray.tif', cv.IMREAD_GRAYSCALE)
print('Image Size is {}'.format(img.shape))
plt.figure(figsize=(10,10))
plt.imshow(img, cmap='gray', vmin=0, vmax=255)
plt.axis('off')
plt.show()

L = 255
neg_img = L - 1 - img
plt.figure(figsize=(10,10))
plt.imshow(neg_img, cmap='gray', vmin=0, vmax=255)
plt.axis('off')
plt.show()

Th = 150
thresh_img = (img >= Th) * 255.0
plt.figure(figsize=(10,10))
plt.imshow(thresh_img, cmap='gray', vmin=0, vmax=255)
plt.axis('off')
plt.show()