#ifndef MOTORDRIVER_H
#define MOTORDRIVER_H
#include <stdint.h>
#include "BaseModule.h"
#include "PID.h"
// MotorDriver class
// Drives electric speed controller, that belongs to electric motor
// Uses PWM method(conversion is defined)
// The PID stabilization, correction routines are here
class MotorDriver : public BaseModule{
public:
    MotorDriver();
    MotorDriver(const MotorDriver& orig);
    virtual ~MotorDriver();
    
    void* ReceiveData();
    uint8_t TransmitData();
    template <uint8_t k>
    void* ReceiveData();
    template <uint8_t k>
    uint8_t TransmitData(void* param_data);
    
    uint8_t GetFeedback();
    uint8_t SendFeedback();
    template <uint8_t k>
    uint8_t GetFeedback();
    template <uint8_t k>
    uint8_t SendFeedback(void* param_data);
    
    
    static bool calibration_mode_;
    
    
private:
    
    uint8_t* esc_comm_pins_;
    uint64_t calibration_delay_;
    uint64_t lower_pulse_bound_;
    uint64_t upper_pulse_bound_;
    
    PID* pitch_pid_controller_;
    PID* roll_pid_controller_;
    PID* yaw_pid_controller_;
    PID* elevation_pid_controller_;
    
    // for init thrust depends on mass and thruster characteristic
    uint64_t init_pulse_;
    
};



#endif /* MOTORDRIVER_H */

