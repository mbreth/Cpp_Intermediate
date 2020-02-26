// Programmer: Morgan Breth
// Date Created: July 16th, 2019

#ifndef PID_h
#define PID_h
#define LIBRARY_VERSION	1.0.0

class PID
{


public:

    //Constants used in some of the functions below
#define AUTOMATIC	1
#define MANUAL	0
#define DIRECT  0
#define REVERSE  1
#define P_ON_M 0
#define P_ON_E 1

//commonly used functions **************************************************************************
    PID(double*, double*, int*,        // * constructor.  links the PID to the Input, Output, and 
        double, double, double, int, int);//   Setpoint.  Initial tuning parameters are also set here.
                                          //   (overload for specifying proportional mode)

    PID(double*, double*, int*,        // * constructor.  links the PID to the Input, Output, and 
        double, double, double, int);     //   Setpoint.  Initial tuning parameters are also set here

    void SetMode(int Mode);               // * sets PID to either Manual (0) or Auto (non-0)

    bool Compute();                       // * performs the PID calculation.  it should be
                                          //   called every time loop() cycles. ON/OFF and
                                          //   calculation frequency can be set using SetMode
                                          //   SetSampleTime respectively

    void SetOutputLimits(double, double); // * clamps the output to a specific range. 0-255 for the Arduino by default, but
                                                              //   it's likely the user will want to change this depending on
                                                              //   the application



  //available but not commonly used functions ********************************************************
    void SetTunings(double, double,
        double);

    void SetTunings(double, double,
        double, int);

    void SetControllerDirection(int);	  // * Sets the Direction, or "Action" of the controller. DIRECT
                                          //   means the output will increase when error is positive. REVERSE
                                          //   means the opposite.  it's very unlikely that this will be needed
                                          //   once it is set in the constructor.
    void SetSampleTime(int);              // * sets the frequency, in Milliseconds, with which 
                                          //   the PID calculation is performed.  default is 100



  //Display functions ****************************************************************
    double GetKp();
    double GetKi();
    double GetKd();
    int GetMode();
    int GetDirection();

private:
    void Initialize();

    double dispKp;
    double dispKi;
    double dispKd;

    double kp;                  // * (P)roportional Tuning Parameter
    double ki;                  // * (I)ntegral Tuning Parameter
    double kd;                  // * (D)erivative Tuning Parameter

    int controllerDirection;
    int pOn;

    double* myInput;
    double* myOutput;
    int* mySetpoint;


    unsigned long lastTime;
    double outputSum, lastInput;

    unsigned long SampleTime;
    double outMin, outMax;
    bool inAuto, pOnE;
};
#endif
