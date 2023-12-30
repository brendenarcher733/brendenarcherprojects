#include <iostream>
#include <map>
#include <string>

class VehicleManager {
private:
    std::map<std::string, std::map<std::string, std::string>> vehicles;

public:
    void addVehicle(const std::string& registrationNumber, const std::string& make,
                    const std::string& model, const std::string& year, const std::string& color) {
        if (vehicles.find(registrationNumber) == vehicles.end()) {
            vehicles[registrationNumber] = {
                {"Make", make},
                {"Model", model},
                {"Year", year},
                {"Color", color}
            };
            std::cout << "Vehicle " << registrationNumber << " added successfully.\n";
        } else {
            std::cout << "Vehicle with registration number " << registrationNumber << " already exists.\n";
        }
    }

    void updateVehicle(const std::string& registrationNumber, const std::string& make = "",
                       const std::string& model = "", const std::string& year = "", const std::string& color = "") {
        auto it = vehicles.find(registrationNumber);
        if (it != vehicles.end()) {
            if (!make.empty()) it->second["Make"] = make;
            if (!model.empty()) it->second["Model"] = model;
            if (!year.empty()) it->second["Year"] = year;
            if (!color.empty()) it->second["Color"] = color;

            std::cout << "Vehicle " << registrationNumber << " updated successfully.\n";
        } else {
            std::cout << "Vehicle with registration number " << registrationNumber << " does not exist.\n";
        }
    }

    void displayVehicleInfo(const std::string& registrationNumber) {
        auto it = vehicles.find(registrationNumber);
        if (it != vehicles.end()) {
            std::cout << "Registration Number: " << registrationNumber << "\n";
            for (const auto& pair : it->second) {
                std::cout << pair.first << ": " << pair.second << "\n";
            }
        } else {
            std::cout << "Vehicle with registration number " << registrationNumber << " does not exist.\n";
        }
    }

    void displayAllVehicles() {
        if (vehicles.empty()) {
            std::cout << "No vehicles in the system.\n";
        } else {
            std::cout << "All Vehicles:\n";
            for (const auto& vehicle : vehicles) {
                std::cout << "Registration Number: " << vehicle.first << "\n";
                for (const auto& pair : vehicle.second) {
                    std::cout << pair.first << ": " << pair.second << "\n";
                }
                std::cout << "-----------------------\n";
            }
        }
    }
};

int main() {
    VehicleManager vehicleManager;

    vehicleManager.addVehicle("ABC123", "Toyota", "Camry", "2022", "Blue");
    vehicleManager.addVehicle("XYZ789", "Honda", "Civic", "2021", "Red");

    vehicleManager.displayAllVehicles();

    vehicleManager.updateVehicle("ABC123", "", "", "", "Green");
    vehicleManager.displayVehicleInfo("ABC123");

    vehicleManager.updateVehicle("PQR456", "Ford", "", "", ""); // Vehicle does not exist

    vehicleManager.displayAllVehicles();

    return 0;
}