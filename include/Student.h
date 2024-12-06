#pragma once
#include <string>
#include <iostream>
#include <format>
#include <vector>
#include <exception>
#include <fstream>
#include <sstream>
#include <filesystem>

inline constexpr const int PASSING_MARKS {32};
inline constexpr const int PASSING_MARKS_X_V2 {70};
inline constexpr const char* QUALIFY_X_V2 {"PASSED - QUALIFIED FOR X v2"};
inline constexpr const char* PASSED {"PASSED"};
inline constexpr const char* FAIL {"FAILED"};

inline constexpr const char* pass_template_jee_adv =
"Congratulations {}!\nYou have successfully cleared X examination.\nYour marks are as follows:\n MATHS : {}\n PHYSICS : {}\n CHEMISTRY : {}\n AVERAGE SCORE : {}\n STATUS: {}\nPlease note, you have also qualified for X v2 examination";

inline constexpr const char* pass_template =
"Congratulations {}!\nYou have successfully cleared X examination.\nYour marks are as follows:\n MATHS : {}\n PHYSICS : {}\n CHEMISTRY : {}\n AVERAGE SCORE : {}\n STATUS: {}\n";

inline constexpr const char* fail_template =
"Dear {},\nYou have been unsuccessful in clearing X examination.\nYour marks are as follows:\n MATHS : {}\n PHYSICS : {}\n CHEMISTRY : {}\n AVERAGE SCORE : {}\n STATUS: {}\n";

class Student
{
public:
	explicit Student(const std::string& name, const uint8_t& maths, const uint8_t& physics, const uint8_t& chemistry) :
		_name{ name }, _maths{ maths }, _physics{ physics }, _chemistry{ chemistry } {
		avg = static_cast<float>(maths + chemistry + physics) / 3;
		pass = avg >= PASSING_MARKS;
	};

	const std::string& get_name() const noexcept { return _name; }
	const uint8_t& get_maths() const noexcept { return _maths; }
	const uint8_t& get_physics() const noexcept { return _physics; }
	const uint8_t& get_chemistry() const noexcept { return _chemistry; }
	const float& get_avg() const noexcept { return avg; }
	const bool& get_status() const noexcept { return pass; }

private:
	std::string _name;
	uint8_t _maths;
	uint8_t _physics;
	uint8_t _chemistry;
	float avg;
	bool pass;
};

const std::vector<Student> read(const std::string&);
void write(const std::vector<Student>&);
void generate_reports(const std::vector<Student>&);