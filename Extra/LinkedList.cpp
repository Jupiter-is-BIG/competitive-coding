using namespace std;

class LinkedList {
    private:
        int n;
    
    public:
        LinkedList(int size) {
            n = size;
        }
        
        void size() {
            cout << n << "\n";
        }
};

int main {
    LinkedList a = new LinkedList(3);
    a.size();
}
