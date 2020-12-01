#include <iostream>
#include <fstream>

using namespace std;

template <class Type> 
class Image {

	int mx;

	int my;

	bool color = 0;

	int counter = 0;

	Type *ptr;

public:

	Image(int tmx, int tmy) {      // Должен инициализировать изображение 0   

		ptr = new Type[tmx*tmy]();   // создание динамического массива под размеры пользователя
		cout << "CONSTRUCTOR CHECK" << this << endl;

	}

	Image(const Image & image_2) {  // конструктор копирования

		cout << "CONSTRUCTOR COPY CHECK" << this;

		this->mx = image_2.mx;
		this->my = image_2.my;
		this->ptr = new Type[mx*my];

		for (int i = 0; i < mx*my; i++) {

			this->ptr[i] = image_2.ptr[i];

		}

	}

	bool operator ==(const Image & image_2) { // передаем адрес второй картинки 
											// перегрузка оператора ==
		bool res = 1;

		for (int i = 0; i < mx*my; i++) {    // сравниваем значения динамических массивов изображений

			if (this->ptr[i] != image_2.ptr[i]) {
				res = 0;
			}

		}

		return res;

	}

	Image & operator =(const Image & image_1) { // перегрузка оператора присваивания

		delete[] this->ptr;

		this->ptr = new Type[mx*my];

		for (int i = 0; i < mx*my; i++) {

			this->ptr[i] = image_1.ptr[i];

		}

		return *this;  // возвращаем значение картинки а

	 }  

	int format(bool clr) { // заполнение кратинки случайными цветами

		color = clr;

		if (color == 1) {
			for (int i = 0; i < mx*my; i++) {
				ptr[i] = rand() % 255;
			}
		}
		else {
			for (int i = 0; i < mx*my; i++) {
				ptr[i] = rand() % 2;
			}
		}

		return color;
	}

	int getMx(int max_x) {

		mx = max_x;

		return mx;

	}

	int getMy(int max_y) {

		my = max_y;

	//	ptr = new int[mx*my]();

		return my;

	}

	void show() {                   // Должен выдавать на экран изображение при помощи printf или       std::cout
		
		counter = 0;
		for (int i = 0; i < mx*my; i++) {


			cout << ptr[i];
			counter++;
			if (counter == mx) {
				cout << endl;
				counter = 0;
			}

		}
		counter = 0;
	}


	void line(int y) {
		counter = mx * (y - 1);
		for (int i = 0; i < mx; i++)
		{
			ptr[counter] = 1;
			counter++;
		}

	}

	void row(int x) {
		counter = 0;
		for (int i = 0; i < my; i++)
		{
			ptr[x + mx * (counter - 1) - 1] = 1;
			counter++;
		}

	}


	int get(int x, int y) {

		cout << "PIXEL IS: " << ptr[x + mx * (y - 1) - 1];

		return 0;

	}

	void set(int x, int y, int color) {

		ptr[x + mx * (y - 1) - 1] = color;

	}

	void save() {
		ofstream file("kartinka.pnm");
		if (color == 0) {
			file << "P1" << endl << mx << " " << my << endl;
			for (int i = 0; i < mx*my; i++) {

				file << ptr[i];
				counter++;
				if (counter == mx) {
					file << endl;
					counter = 0;
				}

			}
			counter = 0;
			file.close(); // закрываем файл
		}
		else {

			file << "P3" << endl << mx << " " << my << endl;
			for (int i = 0; i < mx*my; i++) {

				file << ptr[i] << " ";
				counter++;
				if (counter == mx) {
					file << endl;
					counter = 0;
				}

			}
			counter = 0;
			file.close(); // закрываем файл
		}
		
	}

	~Image() {
		cout << "DESTRUCTOR CHECK" << this << endl;
		delete[] ptr;
	}
};

//Image a(10, 10);

int size_mx, size_my, color_set, x, y, line, row;
bool check = 0, picColor = 0;


int main() {

	cout << endl;
	cout << "Enter mx: ";
	cin >> size_mx;
	cout << "Enter my: ";
	cin >> size_my;

	Image <int> a(size_mx, size_my);   //создаем объекты класса image
//	Image <int> b(size_mx, size_my);

	

	a.getMx(size_mx);
	a.getMy(size_my);
	//b.getMx(size_mx);
	//b.getMy(size_my);

	cout << endl << "Show picture? [1/0]";
	cin >> check;
	if (check == 1) {
		a.show();
		check = 0;
	}

	cout << "Choose PBM or PPM [1/0]: ";
	cin >> picColor;
	a.format(picColor);
	// b.format(picColor);
	if (picColor == 1) {
		cout << "Your picrture will be colored" << endl;
	}
	else {
		cout << "Your picture will be black and white" << endl;
	}

	Image <int> b(a);

/*
	cout << endl << "Chose color: ";
	cin >> color_set;
	cout << endl << "Chose position: ";
	cin >> x >> y;
	b.set(x, y, color_set);  

	cout << endl << "Chose pixel to check: ";
	cin >> x >> y;
	b.get(x, y);  

	cout << endl << "Choose line: ";
	cin >> line;
	a.line(line);

	cout << endl;

	cout << endl << "Show picture? [1/0]";
	cin >> check;
	if (check == 1) {
		a.show();
		check = 0;
	}

	cout << "Choose row: ";
	cin >> row;
	a.row(row);
	
	cout << endl << endl;

	cout << endl << "Show picture? [1/0]";
	cin >> check;
	if (check == 1) {
		cout << "Picture 1 :" << endl;
		a.show();

		cout << endl; // потом удалить

		cout << "Picture 2 :" << endl;
		b.show();

		check = 0;
	}
*/
	bool result = a == b;  // присваиваем переменной result значение сравнения двух изображений с помощью перегруженного оператора ==

	if (result) {
		cout << endl << "Pictures are equal" << endl << endl;
	} else {
		cout << endl << "Pictures are not equal" << endl << endl;
	}

//	b = a;
	cout << "Picture 1 :" << endl;
	a.show();
	cout << endl;
	cout << "Picture 2 :" << endl;
	b.show();
	cout << "RESULT: " << result << endl;
	a.save();

	return 0;
// добваить выбор: либо скопировать изображение A в B и сравнить их, либо создать новое изображение B и сравнивать А с ним
}