#include <iterator>
#include <fstream>
#include <vector>

#include "Paving.hpp"

const size_t MAX_CHARS_PAR_LIGNE = 20;
const char* const DELIMITER = " ";

std::vector<std::vector<float> > matrix;
size_t dim = 0; // simplex dimension

/** \parse permet de parser un fichier
 * \file : le fichier passé en paramètre
 */
void parse(const char* file) {
	ifstream stream;
	stream.open(file); // ouvre un fichier
	if (!stream.good())
		exit(1); // exit si le fichier n'existe pas

	// recupere la première ligne pour la dimension
	std::string firstLine;
	getline(stream, firstLine); //firstLine[2]=2 si N=2 dans 1ere ligne

  dim = firstLine[2] - '0';
	size_t tokenParLigne = dim + 1; //N=2 -> 2 coord + 1 valeur par ligne
	if (tokenParLigne <= 0) {
		std::cout << "dimension doit etre > 0 (il y a " << tokenParLigne << ")" << std::endl;
		exit(1);
	}

	while (!stream.eof()){
		// lis une ligne entière dans la mémoire
		char buffer[MAX_CHARS_PAR_LIGNE];
		stream.getline(buffer, MAX_CHARS_PAR_LIGNE);

		size_t cpt = 0; // pour la boucle for

    // tableau pour stocker les addresses mémoires des tokens dans buffer
    const char* token[tokenParLigne];

    // parse la ligne
    token[0] = strtok(buffer, DELIMITER); // premier token

    if (token[0]){   // zero si il n'y a rien sur la ligne
      for (cpt = 1; cpt < tokenParLigne; cpt++){
        token[cpt] = strtok(0, DELIMITER); // token suivent le token 0
        if (!token[cpt]) break; // pas plus de tokens
      }
    }

    // ajout des éléments
		std::vector<float> line;
		for (size_t i = 0; i < cpt; i++) { // cpt = #des tokens
		  line.push_back(atof(token[i]));
		}

		if(!line.empty())
		  matrix.push_back(line);
	}

	// print
  cout << "Nombre de points : " << matrix.size() << endl;
  cout << "Dimension : "<< dim << "D" << endl << endl;

	stream.close();
}


void usage(const char* nom) {
	std::cout << "Usage : " << nom << "\n"
            << "<file>              input file contient tous les points\n";
}

void TestPoint() {
  std::vector<Point<3> > myVector;

  myVector.push_back(Point<3> (3.4, 3.4, 2.5, 5));
  myVector.push_back(Point<3> (3.4, 3.24, 2.2, 5));
  myVector.push_back(Point<3> (3.4, 3.124, 2.6, 5));
  myVector.push_back(Point<3> (3.4, 3.1, 2.9, 5));

  if (std::find(myVector.begin(), myVector.end(), Point<3> (3.4, 3.1, 2.9, 5)) != myVector.end())  {
    std::cout << "contains\n";
  }

  // print
  for (unsigned i = 0; i < myVector.size(); i++)
    std::cout << myVector[i] << std::endl;
}

template <unsigned int N>
void menu1(Paving<N> pav){
    int option;
    do {
       //Displaying Options for the menu
       cout << endl << "1) Afficher tous les points " << endl;
       cout << "2) Afficher tous les simplexes " << endl;
       cout << "3) Interpoler un point" << endl;
       cout << "4) Exit " << endl;
       cout << "Entrez une option : ";
       cin >> option;
       cout << endl;
       switch(option) {
        case 1 : {pav.to_str();break;}
        case 2 : {pav.to_str_simplex();break;}
        case 3 : {
          std::vector<float> v;
          cout << "Entrez les coordonees du point a interpoler"<<endl;
          for(size_t i=1;i<=N;i++){
            float coor;
            cout << "Inserez la coordonnee "<<i<<endl;
            cin>>coor;
            cout << endl;
            v.push_back(coor);
          }
          const Point<1> p (v, 0);
          cout<<"La valeur interpolee est : "<< pav.interpolateValue(p)<<endl;
          break;
        }
        case 4 : {break;}
        default:{
          cout <<"Choix invalide"<<endl;
          break;
        }

       }

    }
    while(option != 4);
}

template <unsigned int N>
void menu2(Paving<N> pav){
    int option;
    do {
       //Displaying Options for the menu
       cout << endl << "1) Afficher tous les points " << endl;
       cout << "2) Afficher tous les simplexes " << endl;
       cout << "3) Interpoler un point" << endl;
       cout << "4) Exit " << endl;
       cout << "Entrez une option : ";
       cin >> option;
       cout << endl;
       switch(option) {
        case 1 : {pav.to_str();break;}
        case 2 : {pav.to_str_simplex();break;}
        case 3 : {
          std::vector<float> v;
          cout << "Entrez les coordonees du point a interpoler"<<endl;
          for(size_t i=1;i<=N;i++){
            float coor;
            cout << "Inserez la coordonnee "<<i<<endl;
            cin>>coor;
            cout << endl;
            v.push_back(coor);
          }
          const Point<2> p (v, 0);
          cout<<"La valeur interpolee est : "<< pav.interpolateValue(p)<<endl;
          break;
        }
        case 4 : {break;}
        default:{
          cout <<"Choix invalide"<<endl;
          break;
        }

       }

    }
    while(option != 4);
}

template <unsigned int N>
void menu3(Paving<N> pav){
    int option;
    do {
       //Displaying Options for the menu
       cout << endl << "1) Afficher tous les points " << endl;
       cout << "2) Afficher tous les simplexes " << endl;
       cout << "3) Interpoler un point" << endl;
       cout << "4) Exit " << endl;
       cout << "Entrez une option : ";
       cin >> option;
       cout << endl;
       switch(option) {
        case 1 : {pav.to_str();break;}
        case 2 : {pav.to_str_simplex();break;}
        case 3 : {
          std::vector<float> v;
          cout << "Entrez les coordonees du point a interpoler"<<endl;
          for(size_t i=1;i<=N;i++){
            float coor;
            cout << "Inserez la coordonnee "<<i<<endl;
            cin>>coor;
            cout << endl;
            v.push_back(coor);
          }
          const Point<3> p (v, 0);
          cout<<"La valeur interpolee est : "<< pav.interpolateValue(p)<<endl;
          break;
        }
        case 4 : {break;}
        default:{
          cout <<"Choix invalide"<<endl;
          break;
        }

       }

    }
    while(option != 4);
}

template <unsigned int N>
void menu4(Paving<N> pav){
    int option;
    do {
       //Displaying Options for the menu
       cout << endl << "1) Afficher tous les points " << endl;
       cout << "2) Afficher tous les simplexes " << endl;
       cout << "3) Interpoler un point" << endl;
       cout << "4) Exit " << endl;
       cout << "Entrez une option : ";
       cin >> option;
       cout << endl;
       switch(option) {
        case 1 : {pav.to_str();break;}
        case 2 : {pav.to_str_simplex();break;}
        case 3 : {
          std::vector<float> v;
          cout << "Entrez les coordonees du point a interpoler"<<endl;
          for(size_t i=1;i<=N;i++){
            float coor;
            cout << "Inserez la coordonnée "<<i<<endl;
            cin>>coor;
            cout << endl;
            v.push_back(coor);
          }
          const Point<3> p (v, 0);
          cout<<"La valeur interpolee est : "<< pav.interpolateValue(p)<<endl;
          break;
        }
        case 4 : {break;}
        default:{
          cout <<"Choix invalide"<<endl;
          break;
        }

       }

    }
    while(option != 4);
}
int main(int argc, char** argv) {

	if (argc != 2) {
		usage(argv[0]);
		exit(1);
	}

	parse(argv[1]);

	//TestPoint();

	//Paving
	switch(dim) {
  case 1 : { //1D
    std::vector<Point<1> > v_points;
    for(size_t i = 0; i < matrix.size(); i++) {
      // recupère toutes les coordonnées (sauf la dernière)
      std::vector<float> _matrix(matrix[i].begin(), matrix[i].end() - 1);
      // on ajoute la valeur (dernier élément du vector)
      v_points.push_back(Point<1>(_matrix, matrix[i].back()));
    }
    Paving<1> pav(v_points);
    pav.init();
    menu1(pav);
    break; }
  case 2 : { //2D
    std::vector<Point<2> > v_points;
    for(size_t i = 0; i < matrix.size(); i++) {
      std::vector<float> _matrix(matrix[i].begin(), matrix[i].end() - 1);
      v_points.push_back(Point<2>(_matrix, matrix[i].back()));
    }
    Paving<2> pav(v_points);
    pav.init();
    menu2(pav);
    break; }
 case 3 : { //3D
    std::vector<Point<3> > v_points;
    for(size_t i = 0; i < matrix.size(); i++) {
      std::vector<float> _matrix(matrix[i].begin(), matrix[i].end() - 1);
      v_points.push_back(Point<3>(_matrix, matrix[i].back()));
    }
    Paving<3> pav(v_points);
    pav.init();
    menu3(pav);
    break; }
  case 4 : { //4D
    std::vector<Point<4> > v_points;
    for(size_t i = 0; i < matrix.size(); i++) {
      std::vector<float> _matrix(matrix[i].begin(), matrix[i].end() - 1);
      v_points.push_back(Point<4>(_matrix, matrix[i].back()));
    }
    Paving<4> pav(v_points);
    pav.init();
    pav.to_str();
    break; }
	}


	return 0;
}
