#pragma once

class Brain {
	private:
		std::string ideas[100];
	public:
		Brain();
		Brain(const Brain& other);
		~Brain();
		Brain& operator=(const Brain& other);
		void setIdea(const std::string& idea, int index);
		std::string getIdea(int index) const;
};
