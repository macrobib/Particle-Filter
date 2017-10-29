#include <iostream>
#include <random>

auto printSamples(double gps_x, double gps_y, double theta) ->void{

    double std_x = 2.0;
    double std_y = 2.0;
    double std_theta = 0.05;

    std::random_device rd;
    std::mt19937 gen(rd());

    std::normal_distribution<double> dist_x(gps_x, std_x);
    std::normal_distribution<double> dist_y(gps_y, std_y);
    std::normal_distribution<double> dist_theta(theta, std_theta);

    for(auto i = 0; i < 3; i++){
        double sample_x, sample_y, sample_theta;
        sample_x = dist_x(gen);
        sample_y = dist_y(gen);
        sample_theta = dist_theta(gen);

        std::cout<<"Sample: "<< i+1<< " "<< sample_x;
        std::cout<<" "<<sample_y;
        std::cout<<" "<<sample_theta<<std::endl;
    }
}

auto main() -> int{
    double gps_x = 4983;
    double gps_y = 5029;
    double theta = 1.201;

    printSamples(gps_x, gps_y, theta);
}
