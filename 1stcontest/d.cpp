#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int x1, y1, x2, y2;
    int x3, y3, x4, y4;
    
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    
    int rect1_xmin = min(x1, x2);
    int rect1_xmax = max(x1, x2);
    int rect1_ymin = min(y1, y2);
    int rect1_ymax = max(y1, y2);
    
    int rect2_xmin = min(x3, x4);
    int rect2_xmax = max(x3, x4);
    int rect2_ymin = min(y3, y4);
    int rect2_ymax = max(y3, y4);
    
    int area1 = (rect1_xmax - rect1_xmin) * (rect1_ymax - rect1_ymin);
    
    int area2 = (rect2_xmax - rect2_xmin) * (rect2_ymax - rect2_ymin);
    
    int inter_xmin = max(rect1_xmin, rect2_xmin);
    int inter_xmax = min(rect1_xmax, rect2_xmax);
    int inter_ymin = max(rect1_ymin, rect2_ymin);
    int inter_ymax = min(rect1_ymax, rect2_ymax);
    
    int inter_area = 0;
    if (inter_xmin < inter_xmax && inter_ymin < inter_ymax) {
        inter_area = (inter_xmax - inter_xmin) * (inter_ymax - inter_ymin);
    }
    
    int union_area = area1 + area2 - inter_area;
    
    cout << union_area << endl;
    
    return 0;
}