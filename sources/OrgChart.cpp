
#include "OrgChart.hpp"

using namespace std;

namespace ariel{

    // Contructor:
    OrgChart :: OrgChart()
            
            : _manager(NULL){

            }

    /*
    The function receives one input and places it at the root of the tree.
    If there is already something in the root, it is replaced.
    */
    OrgChart& OrgChart :: add_root(string name){

        // If there is no manager:
        if (this->_manager == NULL) {

            // this->_manager = new Node(name);
        }
        
        // If a manager already exists:

        else {

            // להשלים
        }

        return(*this);
    }

    /*
    The function receives two inputs: a person who already exists in the organizational structure,
    and another person who reports to the first person and is below him in the organizational hierarchy.
    */
    OrgChart& OrgChart :: add_sub(string employer, string employee){

        // // If there is no manager:
        // if (this->_manager == NULL){

        //     throw runtime_error("There is no manager");
        // }

        // // If the employer is the manager:
        // if (this->_manager->_name == employer){

        //     // this->_manager->_employees.push_back(new Node(employee));
        // }

        // // If the employer is not the manager:
        // else {

        //     // להשלים עם האיטרטור
        // }

        return *this;
    }

    OrgChart :: iterator OrgChart :: begin_level_order(){

        return OrgChart :: iterator(1);
    }

    OrgChart :: iterator OrgChart :: end_level_order(){

        return OrgChart :: iterator(1);
    }
    
    OrgChart :: iterator OrgChart :: begin_reverse_order(){

        return OrgChart :: iterator(1);
    }
    OrgChart :: iterator OrgChart :: reverse_order(){

        return OrgChart :: iterator(1);
    }

    OrgChart :: iterator OrgChart :: begin_preorder(){

        return OrgChart :: iterator(1);
    }
    OrgChart :: iterator OrgChart :: end_preorder(){

        return OrgChart :: iterator(1);
    }

    OrgChart :: iterator OrgChart :: begin(){

        return OrgChart :: iterator(1);
    }
    OrgChart :: iterator OrgChart :: end(){

        return OrgChart :: iterator(1);
    }

    ostream& operator << (ostream& out, const OrgChart& org){

        out << "out" << "\n";

        return out;
    }

    // Destructor:
    OrgChart :: ~OrgChart(){
        
    }

    OrgChart :: OrgChart(OrgChart &&org) noexcept {
        
        this->_manager = org._manager;
        
        org._manager = nullptr;
    }

       // 	// Move assignment
	// // Transfer ownership of a.m_ptr to m_ptr
	// Auto_ptr4& operator=(Auto_ptr4&& a) noexcept
	// {
	// 	// Self-assignment detection
	// 	if (&a == this)
	// 		return *this;

	// 	// Release any resource we're holding
	// 	delete m_ptr;

	// 	// Transfer ownership of a.m_ptr to m_ptr
	// 	m_ptr = a.m_ptr;
	// 	a.m_ptr = nullptr; // we'll talk more about this line below

	// 	return *this;
	// }

    OrgChart& OrgChart :: operator = (OrgChart &&org) noexcept {

        if (&org == this){

            return *this;
        } 		
        
        this->_manager = org._manager;
        
        org._manager = nullptr;
        
        return *this;
    }

    // 	// Move constructor
	// // Transfer ownership of a.m_ptr to m_ptr
	// Auto_ptr4(Auto_ptr4&& a) noexcept
	// 	: m_ptr(a.m_ptr)
	// {
	// 	a.m_ptr = nullptr; // we'll talk more about this line below
	// }

    // ********************* Iterator Class *********************

    // Iterator Contructor:
	OrgChart :: iterator ::	iterator(int type, Node* ptr)
			
                : _currNodePointer(ptr), _type(type) {

                    // לעשות פה את כל האיתחול
		    }

    string OrgChart :: iterator :: operator * () const {
			
        //return *pointer_to_current_node;
		return this->_currNodePointer->_name;
	}

    string* OrgChart :: iterator :: operator -> () const {
			
        return &(this->_currNodePointer->_name);
	}

    // ++i
    OrgChart :: iterator& OrgChart :: iterator :: operator ++ () {

        // // level order (if type is 1):
        // if (this->_type == 1){

        //     if (_currNodePointer->_employees.size() >= this->_index){

        //         _currNodePointer = _currNodePointer->_next;
        //     }

        //     else if ((*_currNodePointer)._next != nullptr){

        //         _currNodePointer = _currNodePointer->_next;
        //     }
        // }
                
        // // reverse order (if type is 0):
                
        // // preorder (if type is 1):
			
        // //++pointer_to_current_node;
		// _currNodePointer = _currNodePointer->m_next;
			    
        return *this;
	}

    // i++;
	// Usually iterators are passed by value and not by const& as they are small.
	const OrgChart :: iterator OrgChart :: iterator :: operator ++ (int) {
			
        iterator tmp= *this;
		this->_currNodePointer = _currNodePointer->_nextLevelOrder;
		return tmp;
	}

    bool OrgChart :: iterator :: operator == (const iterator& other) const {
			    
        return _currNodePointer == other._currNodePointer;
	}

    bool OrgChart :: iterator :: operator != (const iterator& other) const {
			    
        return _currNodePointer != other._currNodePointer;
	}






}