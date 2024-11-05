#include <iostream>
#include <queue>
#include <time.h>

using namespace std;

class Set {
private:
	int setsize;

public:
	char* data;

	Set() {};

	Set(int size) {
		setsize = size;
		data = new char[size];
		for (int i = 0; i < size; i++) data[i] = -1;
	};

	bool add(int newdata) {
		if (newdata <= setsize && newdata >= 0 && data[newdata] == false) {
			data[newdata]++;
			return true;
		}
		else return false;

	}

	bool all() {
		for (int i = 0; i < setsize; i++) if (data[i] == -1) return false;
	}

	int firstfalse() {
		for (int i = 0; i < setsize; i++) if (data[i] == -1) return i;
	}

	void print() {
		for (int i = 0; i < setsize; i++) {
			cout << (int)data[i] << " " << ends;
		}
	}

	int setmin() {
		char out = 100;
		for (int i = 0; i < setsize; i++) {
			if (data[i] < out && data[i] > 0) out = data[i];
		}
		return out;
	}

	int setmax() {
		char out = -1;
		for (int i = 0; i < setsize; i++) {
			out = max(out, data[i]);
		}
		return out;
	}

};

class List {
public:
	int data;
	List* next;

	List() {
		data = NULL;
		next = nullptr;
	};
	List(int value) : data(value), next(nullptr) {};

	~List() {
		delete next;
	};

	void add(int value) {
		if (data == NULL) {
			data = value;
			return;
		}
		if (next == nullptr) {
			next = new List(value);
		}
		else next->add(value);
	}
	void print() {
		cout << data << " ";
		if (next != nullptr) next->print();
		else {
			cout << endl;
			return;
		}
	};

};

class Graf {
public:
	char** mass;
	int size;
	int grafsize = 0;
	bool isvzvesh = true;
	bool isorient = false;
//	List* list;

	Graf() {};

	Graf(int yoursize) : size(yoursize) {
		mass = new char* [size];
		for (int i = 0; i < size; i++) {
			mass[i] = new char[size];
		}
	}

	void init(char yesno = 1) {
		mass = new char* [size];
		for (int i = 0; i < size; i++) {
			mass[i] = new char[size];
		}
		if (yesno == 1) {
//			list = new List[size];
			for (int i = 0; i < size; i++) {
				for (int j = i; j < size; j++) {
					if (i == j) mass[i][j] = 0;
					else mass[i][j] = mass[j][i] = rand() % 2;
					if (mass[i][j] != 0) {
						grafsize++;
						if (isvzvesh) mass[i][j] = mass[j][i] = (rand() % 10);
						if (isorient) {
							mass[i][j] *= (pow(-1, rand() % 2));
							mass[j][i] = mass[i][j] * -1;
						}
//						list[i].add(j + 1);
//						list[j].add(i + 1);
					}
				}
			}
		}
	}

	void print() {
		cout << endl;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (i == j) cout << " \033[90m#\033[0m";
				else printf("%2i",mass[i][j]);
			}
			cout << endl;
		}
	}

	void clear() {
		for (int i = 0; i < size; i++) {
			delete(mass[i]);
		}
		delete(mass);
	}

	void posh(int v) {
		Set dist(size);
		cout << endl;

		BFSD(v, dist);

		cout << endl;
		dist.print();
		delete dist.data;
	}

	void BFSD(int v, Set dist, bool isprint = true) {
		queue<int> q;
		q.push(v);
		dist.data[v] = 0;
		while (!q.empty()) {
			v = q.front();
			q.pop();
			if (isprint) cout << v + 1 << ", " << ends;
			for (int i = 0; i < size; i++) {
				if (mass[v][i] > 0 && dist.data[i] == -1) {
					q.push(i);
					dist.data[i] = dist.data[v] + mass[v][i];
				}

			}
		}
		
	}
};




int main(int argc, char *argv[]) {
	system("chcp 1251");
	Graf graf;
	srand(time(NULL));

	if (argc > 1 && (strcmp(argv[1], "-v") != 0 || strcmp(argv[1], "-vzvesh") != 0 || strcmp(argv[1], "-o") != 0 || strcmp(argv[1], "-orient") != 0)) 
		if (strcmp(argv[1], "da") == 0 || strcmp(argv[1], "vzvesh") == 0 || strcmp(argv[1], "vzvesheniy") == 0 || strcmp(argv[1], "1") == 0) graf.isvzvesh = true;

	if (argc > 2 && (strcmp(argv[1], "-v") != 0 || strcmp(argv[1], "-vzvesh") != 0 || strcmp(argv[1], "-o") != 0 || strcmp(argv[1], "-orient") != 0))
		if (strcmp(argv[2], "da") == 0 || strcmp(argv[2], "orient") == 0 || strcmp(argv[2], "orientirovaniy") == 0 || strcmp(argv[2], "1") == 0) graf.isorient = true;
	for (int i = 1; i < argc; i++) {
		if (strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "-vzvesh") == 0) 
			if (strcmp(argv[i + 1], "da") == 0 || strcmp(argv[i + 1], "1") == 0) graf.isvzvesh = true; 

		if (strcmp(argv[i], "-o") == 0 || strcmp(argv[i], "-orient") == 0) 
			if (strcmp(argv[i + 1], "da") == 0 || strcmp(argv[i + 1], "1") == 0) graf.isorient = true; 
	}

	cout << graf.isvzvesh << " - " << graf.isorient;

	//std::cout << "Enter graf size: ";
	//std::cin >> graf.size;
	graf.size = 6;

	graf.init();
	graf.print();
	cout << endl << "Enter start point:\n";
	int p = 3;
	//cin >> p;
	p--;
	graf.posh(p);
	if (graf.isvzvesh) {
		Set ex(graf.size);

		for (int i = 0; i < graf.size; i++) {
			Set dist(graf.size);
			graf.BFSD(i, dist, false);
			ex.data[i] = dist.setmax();
			delete dist.data;
		}
		List per, cen;
		int mper = ex.setmax();
		int mrad = ex.setmin();
		for (int i = 0; i < graf.size; i++) {
			if (ex.data[i] == mper) per.add(i);
			if (ex.data[i] == mrad) cen.add(i);
		}
		cout << "\n\nDiametr: " << mper << ", Pereferia: ";
		per.print();
		cout << "Radius: " << mrad << ", Centr: ";
		cen.print();


	}

	graf.clear();
}
