from PIL import Image
import numpy as np

if __name__ == "__main__":
    a = np.loadtxt("out.txt")

    print(a.shape)
    plot = Image.fromarray(np.uint8(a), "L")
    plot.save("./images/plot2.png", "PNG")

