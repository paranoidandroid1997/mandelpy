import math
from turtle import width
from PIL import Image

if __name__ == "__main__":
    XYRATIO = 1.103
    WIDTH = 400
    HEIGHT = math.ceil(WIDTH / XYRATIO)

    delX = 2.47/WIDTH
    delY = 2.47/HEIGHT

    plot = Image.new("RGB", (WIDTH,HEIGHT))
    for x in range(0, WIDTH):
        for y in range(0, HEIGHT):
            scaledX = -2.0 + (x*delX) 
            scaledY = -2.0 + (y*delY)

            real = 0
            imaginary = 0

            step = 0
            maxStep = 1000

            while(real**2 + imaginary**2 <= 4 and step < maxStep):
                imaginary = 2*real*imaginary + scaledY
                real =  real**2 - imaginary**2 + scaledX

                step += 1
            
            if (step > 255):
                step = 254

            plot.putpixel((x,y),(0,0,step))


    plot.save("./images/plot.png","PNG")

