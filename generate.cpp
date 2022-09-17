#include <iostream>
#include <fstream>
#include <vector>


int main(){
    const int WIDTH = 20000;
    const int HEIGHT = (WIDTH / 1.103);

    std::vector<std::vector<int>> steps(HEIGHT, std::vector<int>(WIDTH, 0));

    double delX = 2.47/WIDTH;
    double delY = 2.24/HEIGHT;

    for (int y = 0; y < HEIGHT; y++){
        for (int x = 0; x < WIDTH; x++){
            double scaledX = -2.0 + (x*delX);
            double scaledY = 1.12 - (y*delY);

            double real = 0.0;
            double imaginary = 0.0;

            int step = 0;
            int maxStep = 100;

            while(real*real + imaginary*imaginary <= 4.0 and step < maxStep){
                double realPlaceholder = real*real - imaginary*imaginary + scaledX;
                imaginary = 2.0*real*imaginary + scaledY;
                real =  realPlaceholder;

                step += 1;
            }
            steps[y][x] = step;
        }
    }

    std::ofstream output;
    output.open("out.txt");
    for (int i = 0; i < HEIGHT; i++){
        for (int j = 0; j < WIDTH; j++){
            output << steps[i][j] << " ";
        }
        output << std::endl;
    }
    output.close();

}