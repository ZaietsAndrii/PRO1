#include <iostream>
using namespace std;

int main() {
    int lines, width, segment;
    
    while (cin >> lines >> width >> segment)
    {
        int segmentCounter = 0;
        bool ascendenting = true;
        for (int i = 0; i < lines; i++)
        {
            string line = "";

            if (segmentCounter == 0) ascendenting = true;
            else if(segmentCounter == segment) ascendenting = false;

            for (int l = 0; l < segmentCounter; l++)
            {
                line += " ";
            }
            
            for (int x = 0; x < width; x++)
            {
                line += "*";
            }
            
            
            cout << line << endl;
            if (ascendenting) segmentCounter += 1;
            else segmentCounter -= 1;       
        }
        cout << "" << endl;
    }
    
}