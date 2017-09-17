#ifndef ICT_POSAPP_H__
#define ICT_POSAPP_H__
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "Item.h"
#include "Perishable.h"
#include "NonPerishable.h"
#include "PosIO.h"
#include "POS.h"

namespace ict{
    class PosApp{
    private:
        char m_filename[128], m_billfname[128];
        Item* m_items[MAX_NO_ITEMS];
        int m_noOfItems;
        
        int menu();
        void deallocateItems();
        void loadRecs();
        void saveRecs();
        int searchItems(const char* sku)const;
        void updateQty();
        void addItem(bool isPerishable);
        void listItems()const;
        void truncateBillFile();
        void showBill();
        void addToBill(Item& I);
        void POS();
    public:
        void run();
        PosApp(const char* filename, const char* billfname);
    };
}

#endif
