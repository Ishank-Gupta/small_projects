#include <iostream>
#include <string>
#include <set>

class vehicle {

public:
	vehicle() : m_model(""), m_model_number(""), m_max_speed(0), m_capacity(0), m_color(""), m_year_of_release(0) {}
	//
	void vSetModelNumber(std::string model_number) { m_model_number = model_number; }
	void vSetModel(std::string model) { m_model = model; }
	void vSetMaxSpeed(unsigned int maxSpeed) { m_max_speed = maxSpeed; }
	void vSetCapacity(unsigned int capacity) { m_capacity = capacity; }
	void vSetColor(std::string color) { m_color = color; }
	void vSetYearOfRelease(unsigned int year) { m_year_of_release = year; }
	//
	std::string sGetModelNumber() { return m_model_number; }
	std::string sGetModel() { return m_model; }
	unsigned int uGetMaxSpeed() { return m_max_speed; }
	unsigned int uGetCapacity() { return m_capacity; }
	std::string cGetColor() { return m_color; }
	unsigned int uGetYearOfRelease() { return m_year_of_release; }

private:
	std::string m_model;
	std::string m_model_number;
	unsigned int m_max_speed;
	unsigned int m_capacity;
	std::string m_color;
	unsigned int m_year_of_release;
};

class Models {

public:
	Models() {}
	//
	void addVehicle(std::string model_number);
	void addVehicle(std::string model, int speed, int capacity, std::string color, int year);
	void findModelsByColor(std::string color);
	void findModelsBySpeed(const unsigned int l_speed, const unsigned int h_speed);
	void findModelsByCapacity(const int capacity);
	void findModelsByYear(const int year);
	void printDetails(vehicle details);
	void printDetails();
private:
	vehicle details;
	std::set<vehicle> s_Vehicle_detail;
};

void Models::printDetails(vehicle details) {

	std::cout << "Model Number : " << details.sGetModelNumber() << std::endl;
	std::cout << "Maximum Speed: " << details.uGetMaxSpeed() << std::endl;
	std::cout << "Capacity : " << details.uGetCapacity() << std::endl;
	std::cout << "Color : " << details.cGetColor() << std::endl;
	std::cout << "Year of Release : " << details.uGetYearOfRelease() << std::endl;
}
void Models::printDetails() {
	for (auto itr : s_Vehicle_detail)
		std::cout << itr.sGetModel() << std::endl;
}
void Models::addVehicle(std::string model_number) {

	std::string detail = "";
	int len = model_number.length();
	details.vSetModel(model_number);

	if (len != 17)
	{
		std::cout << "It seems you have entered the wrong model number.\nPlease try again.\n";
		return;
	}

	for (int i = 0; i < len; ++i)
	{
		detail += model_number[i];
		if (i == 4)
		{
			details.vSetModelNumber(detail);
			detail = "";
		}
		if (i == 7) {
			details.vSetMaxSpeed(std::stoi(detail));
			detail = "";
		}
		if (i == 11) {
			details.vSetCapacity(std::stoi(detail));
			detail = "";
		}
		if (i == 12) {
			std::string color = "";
			if (model_number[i] == '1' || model_number[i] == 'R')		color = "Red";
			else if (model_number[i] == '2' || model_number[i] == 'G')	color = "Green";
			else if (model_number[i] == '3'|| model_number[i] == 'B')	color = "Blue";
			details.vSetColor(color);
			detail = "";
		}
		if (i == 16) {
			details.vSetYearOfRelease(std::stoi(detail));
		}
		s_Vehicle_detail.insert(details);
	}

}
void Models::addVehicle(std::string model, int speed, int capacity, std::string color, int year) {
	//
	std::string l_model = model + std::to_string(speed) + std::to_string(capacity) + color[0] + std::to_string(year);
	//
	details.vSetModel(l_model);
	details.vSetModelNumber(model);
	details.vSetMaxSpeed(speed);
	details.vSetCapacity(capacity);
	details.vSetColor(color);
	details.vSetYearOfRelease(year);
}
void Models::findModelsByColor(std::string color) {
	for (auto itr : s_Vehicle_detail)
	{
		if (itr.cGetColor() == color)
			std::cout << itr.sGetModel() << std::endl;
	}
}
void Models::findModelsBySpeed(const unsigned int l_speed, const unsigned int h_speed) {
	for (auto itr : s_Vehicle_detail)
	{
		if (itr.uGetMaxSpeed() >= l_speed || itr.uGetMaxSpeed() <= h_speed )
			std::cout << itr.sGetModel() << std::endl;
	}
}
void Models::findModelsByCapacity(const int capacity) {
	for (auto itr : s_Vehicle_detail)
	{
		if (itr.uGetCapacity() == capacity)
			std::cout << itr.sGetModel() << std::endl;
	}
}
void Models::findModelsByYear(const int year) {
	for (auto itr : s_Vehicle_detail)
	{
		if (itr.uGetMaxSpeed() == year)
			std::cout << itr.sGetModel() << std::endl;
	}
}

int main()
{
	Models model;
	model.addVehicle("BX20A2001500R2016");
	model.addVehicle("BX20A", 200, 1500, "Red", 2016);
	model.printDetails();

	system("pause");
}