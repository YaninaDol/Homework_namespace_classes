#include <iostream>
namespace two_side_list
{
	template<typename T>
	struct Node {
		T value;
		Node* next;
		Node* prev;
	};

	template <typename T>
	class List {
	private:
		Node<T>* head;
		unsigned long size;
	public:
		explicit List()
		{
			this->head = NULL;
			this->size = 0;
		}

		void addToList(T value) {
			Node<int>* tmp = this->head;
			if (tmp == NULL) {
				tmp = new Node<T>;
				tmp->value = value;
				tmp->next = nullptr;
				tmp->prev = nullptr;
				this->head = tmp;
			}
			else {
				while (tmp->next != nullptr)
				{
					tmp = tmp->next;
				}

				tmp->next = new Node<T>;
				tmp->next->value = value;
				tmp->next->next = nullptr;
				tmp->next->prev = tmp;
			}
			this->size++;
		}
		bool isInList(T value) {
			bool isIn = false;
			Node<int>* tmp = this->head;
			while (tmp != nullptr)
			{
				if (tmp->value == value)
				{
					isIn = true;
					break;
				}
				tmp = tmp->next;
			}
			tmp = nullptr;

			return isIn;
		}

		void removeFromList(T value) {
			if (this->isInList(value)) {
				Node<T>* forDelete;
				if (this->head->value == value) {
					forDelete = this->head;
					this->head = this->head->next;
					this->head->prev = nullptr;
				}
				else {
					Node<T>* tmp = this->head;
					forDelete = tmp;
					while (tmp->next != nullptr)
					{
						if (tmp->next->value == value) {
							forDelete = tmp->next;
							tmp->next->prev = tmp;
							break;
						}
						tmp = tmp->next;
					}
					tmp->next = tmp->next->next;
					if (tmp->next != nullptr) {
						tmp->next->prev = tmp;
					}
				}
				delete forDelete;
				this->size--;
			}
		}

		void showList() {
			Node<int>* tmp = this->head;
			while (tmp != nullptr)
			{
				std::cout << " Adress:" << tmp << "\t value: " << tmp->value << "\t prev: " << tmp->prev << "\t next:" << tmp->next << "\n";
				tmp = tmp->next;
			}
			delete tmp;
		}
		unsigned long getSize()
		{
			return this->size;
		}
	};




}


