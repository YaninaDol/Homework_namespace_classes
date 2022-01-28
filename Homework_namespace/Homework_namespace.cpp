#include "Binary_tree.h"
#include "two_side_list.h"
#include "one_side_list.h"
int main()
{
	//namespace Binary_tree

	std::cout << "\n Binary tree : \n\n";
	int size;
	int value;


	std::cout << "Enter size : ";
	std::cin >> size;


	Binary_tree::Tree<int> one;
	
	for (int i = 0; i < size; ++i)
	{
		std::cout << " Enter value : ";
		std::cin >> value;
		one.add(value);
	}

	std::cout << " Tree : \n";
    one.showList();

	one.Delete();

	std::cout << " --------------- \n ";
	one.add(10);
	one.showList();


	// Односвязный список, пространство one_side_list

	std::cout << "\n One side list : \n\n";
	one_side_list::List<int> numbs1;

	numbs1.addToList(1);
	numbs1.addToList(2);
	numbs1.addToList(3);
	numbs1.addToList(4);
	numbs1.addToList(5);

	numbs1.showList();
	std::cout << "\n\n";

	std::cout << "is 1 in list?\t" << numbs1.isInList(1) << "\n";
	std::cout << "is 11 in list?\t" << numbs1.isInList(11) << "\n";

	std::cout << "\n\n";
	numbs1.removeFromList(1);

	numbs1.removeFromList(45);
	numbs1.showList();



	// Двусвязный список, пространство two_side_list

	std::cout << "\n\n Two side list : \n\n";
	two_side_list::List<int> numbs2;

	numbs2.addToList(1);
	numbs2.addToList(2);
	numbs2.addToList(3);
	numbs2.showList();
	std::cout << "\n\n\n";

	std::cout << "is 3 in list?\t" << numbs2.isInList(3) << "\n";
	std::cout << "is 33 in list?\t" << numbs2.isInList(33) << "\n";

	std::cout << "\n\n\n";
	numbs2.removeFromList(3);

	numbs2.removeFromList(65);
	numbs2.showList();

	
}

