#include <iostream>
using namespace std;

class XMLData {
    private:
        string xmlData;
    public:
        XMLData(string pxmlData) {
            xmlData = pxmlData;
        }
        string getXMLData() {
            return xmlData;
        }
};

class DataAnalyticsTool {
    private:
        string jsonData;
    public:
        DataAnalyticsTool() {}; // if prmtzed ctor is define, then default ctor def is must.
        DataAnalyticsTool(string pjsonData) {
            jsonData = pjsonData;
        }

        // Made virtual as part of Adapter
        virtual void analyseData() {
            cout << "Analysing data (old method)" << endl;
        }
};

class Adapter : public DataAnalyticsTool {
    private:
        XMLData* xmlData;
    public:
        Adapter(XMLData* pxmlData) {
            xmlData = pxmlData;
        }
        void analyseData() {
            cout << "Converting XML data " << xmlData->getXMLData() << " to JSON data" << endl;
            cout << "Analysing the converted JSON data" << endl;
        }
};

class Client {
    public:
        void processData(DataAnalyticsTool* tool) {
            tool->analyseData();
        }
};

int main() {
    XMLData* xml = new XMLData("Sample xml data");

    // we can't pass xml ptr to this DataAnalyticsTool object
    // because it's expecting json to process. Here we need Adapter class.
    DataAnalyticsTool* tool = new Adapter(xml);
    Client* client = new Client;
    client->processData(tool);
}