#pragma once
namespace mystd {
	template<typename T, typename U, typename I>
	class IODevice {
	protected:
		T model;
		U yearofissue;
		I manufacturer;
	public:

		IODevice() {};
		virtual void print() = 0;
		~IODevice() {};
	};
	template<typename T, typename U, typename I>
	class Typewriter :public IODevice<T, U, I> {

	public:
		Typewriter(std::string mod, std::string y, std::string man) { model = mod; yearofissue = y; manufacturer = man; };
		//Typewriter() {}
		//~Typewriter() {}
		void print();
	};
	template<typename T, typename U, typename I>
	class Printer :public IODevice<T, U, I> {

	public:
		//Printer() {};
		//~Printer() {};
		Printer(std::string mod, std::string y, std::string man) { model = mod; yearofissue = y; manufacturer = man; };
		void print();
		void printCopy();
		void printWithStep(const int x);
		void printReverse();
		void printСoncordance(const std::string s);
	};
	template<typename T, typename U, typename I>
	void Typewriter<T, U, I>::print() {
		std::cout << "model: ";
		std::cout << model << std::endl << "yearofissue: " << yearofissue << std::endl << "manufacturer: " << manufacturer << std::endl;
	}
	template<typename T, typename U, typename I>
	void Printer<T, U, I>::print() {
		std::cout << "model: ";
		std::cout << model << std::endl << "yearofissue: " << yearofissue << std::endl << "manufacturer: " << manufacturer << std::endl;
	}

	template<typename T, typename U, typename I>
	inline void Printer<T, U, I>::printCopy()
	{
		std::ifstream in;
		in.open("input.txt");
		if (!in.is_open()) {
			std::cout << "File not found" << std::endl;
			return; //exit(1);
		}
		std::vector<std::string> myvector;
		std::string str;
		while (!in.eof()) {
			in >> str;
			myvector.push_back(str);
		}
		std::ofstream fout("output.txt");
		if (!fout.is_open()) // если файл небыл открыт 
		{
			std::cout << "Файл не может быть открыт или создан\n";
			return;
		}
		for (std::vector<std::string>::iterator it = myvector.begin(); it != myvector.end(); ++it) {
			fout << ' ' << *it;
		}
		myvector.clear();	// :p
		in.close();
		fout.close();
	}

	template<typename T, typename U, typename I>
	inline void Printer<T, U, I>::printWithStep(const int x)
	{
		std::ifstream in;
		in.open("input.txt");
		if (!in.is_open()) {
			std::cout << "File not found" << std::endl;
			return; //exit(1);
		}
		std::vector<std::string> myvector;
		std::string str;
		while (!in.eof()) {
			in >> str;
			myvector.push_back(str);
		}
		std::ofstream fout("output.txt");
		if (!fout.is_open()) // если файл небыл открыт 
		{
			std::cout << "Файл не может быть открыт или создан\n";
			return;
		}
		std::vector<std::string>::size_type sz = myvector.size();
		//std::vector<std::string>::iterator it = myvector.begin();
		for (unsigned i = 0; i < sz; i++) {
			if ((i + 1) % x == 0)fout << ' ' << myvector[i];
		}
		myvector.clear();	// :p
		in.close();
		fout.close();
	}

	template<typename T, typename U, typename I>
	inline void Printer<T, U, I>::printReverse()
	{
		std::ifstream in;
		in.open("input.txt");
		if (!in.is_open()) {
			std::cout << "File not found" << std::endl;
			return; //exit(1);
		}
		std::vector<std::string> myvector;
		std::string str;
		while (!in.eof()) {
			in >> str;
			myvector.push_back(str);
		}
		std::ofstream fout("output.txt");
		if (!fout.is_open()) // если файл небыл открыт 
		{
			std::cout << "Файл не может быть открыт или создан\n";
			return;
		}
		std::vector<int>::size_type sz = myvector.size();
		for (unsigned i = 0; i < sz / 2; i++)
		{
			std::string temp;
			temp = myvector[sz - 1 - i];
			myvector[sz - 1 - i] = myvector[i];
			myvector[i] = temp;
		}
		for (std::vector<std::string>::iterator it = myvector.begin(); it != myvector.end(); ++it) {
			fout << ' ' << *it;
		}
		myvector.clear();	// :p
		in.close();
		fout.close();
	}

	template<typename T, typename U, typename I>
	inline void Printer<T, U, I>::printСoncordance(const std::string s)
	{
		std::ifstream in;
		in.open("input.txt");
		if (!in.is_open()) {
			std::cout << "File not found" << std::endl;
			return; //exit(1);
		}
		std::ofstream fout("output.txt");
		if (!fout.is_open()) // если файл небыл открыт 
		{
			std::cout << "Файл не может быть открыт или создан\n";
			return;
		}
		std::string str;
		while (!in.eof()) {
			getline(in, str);
			size_t pos = str.find(s);
			if (pos != std::string::npos) {
				fout << str;
			}
		}
		in.close();
		fout.close();
	}
}