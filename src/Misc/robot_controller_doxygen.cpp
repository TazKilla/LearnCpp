#include <string>

/**
 * @brief Controller class for robot movement
 * @details Handles basic movement operations and speed control for the robot
 *          Found on the web...
 */
class RobotController {
    private:
        double maxSpeed;
        std::string robotName;
    
    public:
        /**
         * @brief Construct a new Robot Controller object
         * 
         * @param name The name identifier for the robot
         * @param speed The maximum speed in meters per second
         */
        RobotController(std::string name, double speed);
        /**
         * @brief Moves the robot forward by the specified distance
         * 
         * @param distance The distance to move in meters
         * @return void
         */
        void moveForward(double distance);
};