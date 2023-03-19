#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename K, typename V>
class AssociativeArray {
    private:
        vector<pair<K, V>> jimmy;
    public:
        void put(K key, V value) {
            pair<K, V> price;
            price.first = key;
            price.second = value;
            jimmy.push_back(price);
        }

        V get(K key) {
            for(int i = 0; i<jimmy.size(); i++) {
                if(jimmy[i].first == key) {
                    return jimmy[i].second;
                }
            }
            return 0;
        }
};

int main() {
    AssociativeArray<string, double> prices;

    prices.put("Toaster Oven", 19.95);
    prices.put("Car Vacuum", 24.99);

    cout << "Toaster Oven: " << prices.get("Toaster Oven") << endl;
}