#include <iostream>
#include <fstream>
#include <string>

/**
 * CarCounter Class
 * Manages the counting logic and data persistence to a local file.
 */
 class CarCounter {
    private:
       int totalCars;
       const std::string filename = "traffic_data.text";
 
       void saveData() {
        std::ofstream file(filename);
        if (file.is_open()) {
            file << totalCars;
            file.close();
        
        }
       }

       void loadData() {
        std::ifstream file(filename);
        if (file.is_open()) {
            file >> totalCars;
            file.close();
        } else {
            totalCars = 0; // Initialize if file doesn't exist
        }
       }
    
      public:
      CarCounter() {
        loadData();
      }

      void registerCar() {
        totalCars++;
        saveData();
        std::cout << "[LOG] Vehicle detected. Current count: " << totalCars << std::endl; 
      }

      void resetCounter() {
        totalCars = 0;
        saveData();
        std::cout << "[SYSTEM] Counter has been reset to zero." << std::endl;
      }

      void displayReport() const {
        std::cout << "\n=========================" << std::endl;
        std::cout << "   TRAFFIC CONTROL REPORT  " << std::endl;
        std::cout << " Total vehicles logged: " << totalCars << std::endl;
        std::cout << "===========================" << std::endl;
      }
    };

    int main() {
        CarCounter laneOne;
        char input;

        std::cout << "--- Smart Lane Counter System (Simulation) ---" << std::endl;
        std::cout << "Commands: [a] Add Car | [r] Report | [c] Clear | [q] Quit" << std::endl;

        while (true) {
            std::cout << ">> Enter command: ";
            std::cin >> input;

            if (tolower(input) == 'q') break;

            switch (tolower(input)) {
                case 'a':
                laneOne.registerCar();
                break;
                case 'r':
                laneOne.displayReport();
                break;
                case 'c':
                laneOne.resetCounter();
                break;
                default:
                std::cout << "Invalid command. Try again." << std::endl;

            }
        }

        std::cout << "Shutting down system. Data saved." << std::endl;
        return 0;
    }