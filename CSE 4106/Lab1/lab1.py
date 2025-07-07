# %% [markdown]
# Breakdown:
# - Board Viva: 25 marks
# - Lab Report (Soft Copy - LaTeX or Overleaf): 10% (7.5 marks)
#     - Deadline: Before next lab
# - Lab Final: 50% (37.5 marks)
# - Lab Quiz: 10-15%
# - Lab Assessment: 10-15%
# - Attendance: 10 marks
# 
# Week Numbers: 1 3 5 7 9 11
# 
# Topics:
# - Python Basics
#     - Loop
#     - Array (NumPy array)
#     - Function / Method
# - OpenCV (BGR)
#     - how to open a image
#     - read, display, write
# -Matplotlib - (RGB)
#     - sub plot 
# 
# 
# why openCV works in BGR space and Matplotlib works in RGB space 
# and why the same image shows different in these method 
# (R,B swaping may be the cause)
# 
# color space conversion 
# 
# HSV
# 
# CV2.imshow
# 
# plt.show()

# %%
import cv2
import matplotlib.pyplot as plt
import numpy as np

# %%
for i in range(5):
    print(f"Loop iteration: {i}")


array = np.array([1, 2, 3, 4, 5])
print("NumPy Array:", array)

def square_elements(arr):
    return np.square(arr)

squared_array = square_elements(array)
print("Squared Array:", squared_array)

# %%
image_bgr = cv2.imread('images/image1.jpg')
plt.subplot(1, 2, 1)
plt.imshow(image_bgr)

# %%
plt.subplot(1, 2, 1)
plt.title('Image in Matplotlib')
plt.imshow(image_bgr)

image_hsv = cv2.cvtColor(image_bgr, cv2.COLOR_BGR2HSV)

cv2.imshow('HSV Image', image_hsv)
cv2.imwrite('output_image_hsv.jpg', image_hsv)
cv2.waitKey(0)
cv2.destroyAllWindows()


plt.subplot(1, 2, 2)
plt.title('HSV Image in Matplotlib')
plt.imshow(image_hsv)
plt.show()


