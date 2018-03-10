#include "PID.h"
#include <limits>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    
    //Intialize co-efficients
    
    //intialize errors
    //setting the p_error
    p_error = 0.0;
    i_error = 0.0;
    d_error = 0.0;
    
    this->Kp = Kp; // propotional coeff
    this->Ki = Ki; //Integral coeff
    this->Kd = Kd; //Differntail coeff
    
  
    
}

void PID::UpdateError(double cte) {
   
    if(p_error == numeric_limits<double>::max())
        p_error = cte;
    d_error = cte - p_error;
    p_error = cte;
    i_error += cte;
   
}

double PID::TotalError() {
    return Kp * p_error + Ki * i_error + Kd * d_error;
}

