#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{

    //========================
    // KHU VỰC 1: Lambda cơ bản
    //========================

    // Lambda giống như một hàm ngắn viết trực tiếp
    auto sum = [](int a, int b)
    {
        return a + b; // trả về tổng
    };

    cout << "Lambda sum: " << sum(3,5) << endl; // gọi lambda như hàm bình thường



    //========================
    // KHU VỰC 2: Lambda với sort()
    //========================

    vector<int> v = {4,1,7,3,2}; // vector ban đầu

    // Sắp xếp giảm dần bằng lambda
    sort(v.begin(), v.end(),
        [](int a, int b)
        {
            return a > b; // nếu a > b thì a đứng trước
        }
    );

    cout << "Sort giam dan: ";

    for(int x : v) // duyệt vector
        cout << x << " ";

    cout << endl;



    //========================
    // KHU VỰC 3: Lambda với find_if()
    //========================

    vector<int> a = {3,7,2,9,4}; // vector dữ liệu

    // Tìm phần tử chẵn đầu tiên
    auto it = find_if(a.begin(), a.end(),
        [](int x)
        {
            return x % 2 == 0; // điều kiện: số chẵn
        }
    );

    if(it != a.end()) // kiểm tra có tìm thấy không
        cout << "So chan dau tien: " << *it << endl;



    //========================
    // KHU VỰC 4: Lambda với for_each()
    //========================

    vector<int> b = {1,2,3,4};

    cout << "Nhan doi tung phan tu: ";

    // for_each sẽ chạy lambda cho từng phần tử
    for_each(b.begin(), b.end(),
        [](int x)
        {
            cout << x * 2 << " "; // in ra gấp đôi
        }
    );

    cout << endl;



    //========================
    // KHU VỰC 5: Lambda capture biến bên ngoài
    //========================

    int k = 5; // biến bên ngoài lambda

    vector<int> c = {2,4,6,8,3};

    // Tìm số đầu tiên lớn hơn k
    auto it2 = find_if(c.begin(), c.end(),
        [k](int x) // capture biến k
        {
            return x > k;
        }
    );

    if(it2 != c.end())
        cout << "So dau tien > k: " << *it2 << endl;



    //========================
    // KHU VỰC 6: Lambda với pair (rất hay gặp trong DSA)
    //========================

    vector<pair<int,int>> p = {
        {1,5},
        {2,3},
        {4,2},
        {3,7}
    };

    // sort theo second
    sort(p.begin(), p.end(),
        [](pair<int,int> a, pair<int,int> b)
        {
            return a.second < b.second; // so sánh second
        }
    );

    cout << "Sort theo second: ";

    for(auto x : p)
        cout << "(" << x.first << "," << x.second << ") ";

    cout << endl;



    return 0;
}