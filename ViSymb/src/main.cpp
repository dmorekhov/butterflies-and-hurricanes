#include <SymbolManager.h>

using namespace std;

int main() {
    QString filePath = "C:/Users/mitya/OneDrive/Документы/Studystudy/oopcpp/butterflies-and-hurricanes/ViSymb/data/symbols.json";
    SymbolManager symbolManager;
    symbolManager.loadSymbols(filePath);
    symbolManager.printSymbols();
    return 0;
}
