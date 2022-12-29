#include <fstream>
#include <vector>
using namespace std;



int main() {
    // Membuat vector array yang akan disimpan
    vector<vector<int>> data = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    // Membuka file untuk ditulis
    std::ofstream out("data.txt");

    // Menulis data vector array ke dalam file
    for (const vector<int>& row : data) {
        for (int i : row) {
            out << i << ' ';
        }
        out << '\n';
    }

    // Menutup file
    out.close();

    return 0;
}