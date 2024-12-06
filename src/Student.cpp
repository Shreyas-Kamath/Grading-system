#include "Student.h"

const std::vector<Student> read(const std::string& filename) {
	try {
		std::ifstream file(filename); std::string line,name, maths, phy, chem;
		std::vector<Student> vec;
		if (file.is_open()) {
			while (std::getline(file, line)) {
				std::stringstream ss(line);
				if (std::getline(ss, name, ',') &&
					std::getline(ss, phy, ',') &&
					std::getline(ss, chem, ',') &&
					std::getline(ss, maths, ',')) {
					vec.emplace_back(name, static_cast<uint8_t>(std::stoi(maths)),
						static_cast<uint8_t>(std::stoi(phy)),
						static_cast<uint8_t>(std::stoi(chem)));
				}
			}
		}
		file.close();
		return vec;
	}
	catch (std::exception& ex) {
		std::cout << ex.what() << '\n';
	}
}


void write(const std::vector<Student>& students) {
	try {
		std::ofstream file("RESULTS.csv", std::ios::trunc);
		if (file.is_open()) {
			file << "NAME,PHYSICS,CHEMISTRY,MATHS,AVERAGE,STATUS\n";
			for (const Student& student : students) {
				file << student.get_name() << ','
					<< static_cast<int>(student.get_physics()) << ','
					<< static_cast<int>(student.get_chemistry()) << ','
					<< static_cast<int>(student.get_maths()) << ','
					<< student.get_avg() << ','
					<< ((student.get_avg() >= PASSING_MARKS_X_V2) ? QUALIFY_X_V2 : student.get_status() ? PASSED : FAIL)
					<< '\n';
			}
		}
		file.close();
	}
	catch (std::exception& ex) {
		std::cout << ex.what();
	}
}

void generate_reports(const std::vector<Student>& students) {
	std::filesystem::create_directory("INDIVIDUAL REPORTS");
	std::filesystem::current_path("INDIVIDUAL REPORTS");
	for (const Student& student : students) {
		std::string status = ((student.get_avg() >= PASSING_MARKS_X_V2) ? QUALIFY_X_V2 : student.get_status() ? PASSED : FAIL);
		std::string filename = student.get_name() + " - " + status+".txt";
		std::ofstream file(filename, std::ios::trunc);
		if (file.is_open()) {
			if (status == QUALIFY_X_V2) {
				std::string write = std::format(pass_template_jee_adv, student.get_name(), student.get_maths(), student.get_physics(), student.get_chemistry(), student.get_avg(), student.get_status() ? PASSED:FAIL);
				file << write;
				file.close();
			}
			else if (status == PASSED) {
				std::string write = std::format(pass_template, student.get_name(), student.get_maths(), student.get_physics(), student.get_chemistry(), student.get_avg(), student.get_status() ? PASSED : FAIL);
				file << write;
				file.close();
			}
			else {
				std::string write = std::format(fail_template, student.get_name(), student.get_maths(), student.get_physics(), student.get_chemistry(), student.get_avg(), student.get_status() ? PASSED : FAIL);
				file << write;
				file.close();
			}
		}
	}
}