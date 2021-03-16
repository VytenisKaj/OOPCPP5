#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED

#include<string>

namespace MyCar{

    class Car{

        private:

            class CarPrivate;
            CarPrivate *info;

        public:
            Car();
            Car(const std::string& manufacturer, const std::string& model, unsigned int manufactureYear, const std::string& color,
                const std::string& plate, const std::string& vin, unsigned int enginePower, unsigned int weight);
            ~Car();

            // Getters
            std::string getColor() const;
            std::string getVin() const;
            std::string getPlate() const;
            unsigned int getEnginePower() const;
            unsigned int getWeight() const;
            std::string getManufacturer() const;
            std::string getModel() const;
            unsigned int getManufactureYear() const;
            unsigned int getID() const;

            // Setters
            void setColor(const std::string& color);
            void setVin(const std::string& vin);
            void setPlate(const std::string& plate);
            void setEnginePower(unsigned int enginePower);
            void setWeight(unsigned int weight);
            void setManufacturer(const std::string& manufacturer);
            void setModel(const std::string& model);
            void setManufactureYear(unsigned int manufactureYear);

            std::string toString() const;

            // Comparison operators (compares IDs)
            bool operator==(const Car& object) const;
            bool operator!=(const Car& object) const;
            bool operator<(const Car& object) const;
            bool operator<=(const Car& object) const;
            bool operator>(const Car& object) const;
            bool operator>=(const Car& object) const;

            // Gives new unused ID
            Car& operator++();
            Car operator++(int);

            // Copies objects
            void operator=(const Car& object);


            friend std::ostream& operator<<(std::ostream& stream, const Car& object);
            friend std::istream& operator>>(std::istream& stream, Car& object);

            friend class CarChecker;
            friend class CarPrivate;
    };

    // Exception if object is incomplete
    class incomplete_object: public std::exception{
        private:
            std::string msg;
        public:
            incomplete_object(const std::string &msg){
                this->msg = msg;
            }
            virtual const char* what() const noexcept{
                return msg.c_str();
            }
    };
}
#endif // CAR_H_INCLUDED
