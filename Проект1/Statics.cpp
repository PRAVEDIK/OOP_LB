#include "Statics.h"

double Statics::SummCost(IStorageDevice* sd)
{
    Costsum += sd->get_costSD();
    Stats[sd]++;
    return Costsum;
}

double  Statics::SummCost(TemplateTree<IStorageDevice>* tr)
{
    for (int i = tr->Get_count()-1; i > 0; i--) {
        SummCost(tr->getitem(i));
    }
    return Costsum;
}

void Statics::print()
{
    cout << "Сумма пассажиров во всех воздушных тс: " << Costsum << endl;
    for each (auto var in Stats)
    {
        cout << var.first->get_nameStoregeDevice() << " " << var.second << endl;
    }
    cout << Costsum << endl;
}
