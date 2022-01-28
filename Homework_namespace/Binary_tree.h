#include <iostream>

namespace Binary_tree 
{
	template<typename T>

	struct Node {
		T value;
		Node* right;
		Node* left;
	};

	template <typename T>
	class Tree {

	private:
		Node<T>* head;

		void addToTree(T value, Node<int>** nowNode)
		{

			if ((*nowNode) == NULL) {
				(*nowNode) = new Node<T>;
				(*nowNode)->value = value;
				(*nowNode)->right = NULL;
				(*nowNode)->left = NULL;

				return;
			}
			else {

				if (value > (*nowNode)->value)
				{
					addToTree(value, &(*nowNode)->right);

				}
				else
				{
					addToTree(value, &(*nowNode)->left);

				}

			}

		}
		void showList(Node<int>* tmp, int value) {

			if (tmp == NULL)return;
			else
			{
				showList(tmp->left, ++value);
				for (int i = 0; i < value; ++i)
				{
					std::cout << "|";
				}
				std::cout << tmp->value << "\n";
				value--;

			}
			showList(tmp->right, ++value);

		}

		void Dell(Node<int>* tmp)
		{

			if (tmp == NULL)return;
			else
			{
				if (tmp->left) Dell(tmp->left);
				if (tmp->right) Dell(tmp->right);
				delete tmp;
			}
		}
	public:
		Tree()
		{
			this->head = NULL;

		}


		void add(T value)
		{
			Node<T>** tmp = &this->head;
			this->addToTree(value, tmp);
		}

		void showList()
		{

			this->showList(this->head, 0);
		}


		void Delete()
		{
			this->Dell(this->head);
			this->head = nullptr;

		}
	};



}
