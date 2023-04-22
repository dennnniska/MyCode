#include "mainwindow.h"
#include "ui_mainwindow.h"

QVector<QString> get_mas(QString a){
    QVector<QString>ans;
    QString b = "";
    for (int i = 0; i < a.size(); i++){
        if(a[i] != ','){
            b += a[i];
        }else{
            ans.push_back(b);
            b = "";
        }
    }
    if (b.size() != 0){
        ans.push_back(b);
    }
    return ans;
}

static int randomBetween(int low, int high)
{
    return (qrand() % ((high + 1) - low) + low);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //this->resize(640,640);          // Устанавливаем размеры окна приложения
        //this->setFixedSize(640,640);

        scene = new QGraphicsScene(this);   // Инициализируем графическую сцену
        scene->setItemIndexMethod(QGraphicsScene::NoIndex); // настраиваем индексацию элементов
        ui->graphicsView->resize(600,600);  // Устанавливаем размер graphicsView
        ui->graphicsView->setScene(scene);  // Устанавливаем графическую сцену в graphicsView
        ui->graphicsView->setRenderHint(QPainter::Antialiasing);    // Настраиваем рендер
        ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground); // Кэш фона
        ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
        connect(scene,SIGNAL(changed(QList<QRectF>)),SLOT(update()));
        //scene->setSceneRect(0,0,500,500); // Устанавливаем размер сцены
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    kol++;
    QString name =  ui->name->text();
    QString fname = ui->fname->text();
    auto it = del.find(name);
    if(it != del.end()){
        QMessageBox::warning(this, "Ошибка", "Узел с именем " + name + " уже существует");
        return;
    }
    MoveItem *item = new MoveItem(0, kol, name, fname);        // Создаём графический элемента
    item->setPos(randomBetween(30, 470),    // Устанавливаем случайную позицию элемента
                 randomBetween(30,470));
    scene->addItem(item); // Добавляем элемент на графическую сцену
    del[name] = item;
    item->del = &par;
}



void MainWindow::on_pushButton_2_clicked()
{
    for(auto iter = del.begin(); del.end()!= iter; iter++){
        delete *iter;
    }
    del.clear();
    par.clear();
    kol = 0;
}


void MainWindow::on_Button_del_clicked()
{
    QString del_st = ui->del_uz->text();
    QVector<QString> delp = get_mas(del_st);
    for(int k = 0; k < delp.size(); k++){
    auto it = del.find(delp[k]);
    if (it != del.end()){
        for(auto i = par.begin(); i != par.end(); i++){
            for(auto j = i->begin(); j != i->end(); j++){
                if(j->first == del[delp[k]]){
                    i->erase(j);
                }
            }
        }
        par[del[delp[k]]].clear();
        auto ite = par.find(del[delp[k]]);
        par.erase(ite);
        delete del[delp[k]];
        del.erase(it);
    }
    }
    qDebug() << del_st;
}


void MainWindow::on_But_add_clicked()
{
    QString first = ui->add_1->text();
    QString second = ui->add_2->text();
    QString len = ui->len->text();
    if (len.size() == 0){
        len = "1";
    }
    for (int i = 0; i < len.size(); i++){
        if( len[i] < '0' || len[i] > '9'){
            QMessageBox::warning(this, "Ошибка", "ВВедено не число в вес");
            return;
        }
    }
    int len_int = len.toInt();
    auto it = del.find(first);
    auto it1 = del.find(second);
    if (it ==  del.end() || it1 ==  del.end()){
        QMessageBox::warning(this, "Ошибка", "Не найдены узлы");
        return;
    }
    for (auto iter = par[del[first]].begin(); iter != par[del[first]].end(); iter++){
        if (iter->first == del[second]){
            iter->second = len_int;
            break;
        }
    }
    for (auto iter = par[del[second]].begin(); iter != par[del[second]].end(); iter++){
        if (iter->first == del[first]){
            iter->second = len_int;
            return;
        }
    }
    par[del[first]].append({del[second], len_int});
    par[del[second]].append({del[first], len_int});

}


void MainWindow::on_but_del_reb_clicked()
{
    QString first = ui->del_1->text();
    QString second = ui->del_2->text();
    auto it = del.find(first);
    auto it1 = del.find(second);
    if (it ==  del.end() || it1 ==  del.end()){
        return;
    }
    bool f = false;
    for (auto iter = par[del[first]].begin(); iter != par[del[first]].end(); iter++){
        if (iter->first == del[second]){
            par[del[first]].erase(iter);
            f = true;
            break;
        }
    }
    for (auto iter = par[del[second]].begin(); iter != par[del[second]].end(); iter++){
        if (iter->first == del[first]){
            par[del[second]].erase(iter);
            f = true;
            break;
        }
    }
    if(!f){
        QMessageBox::warning(this, "Ошибка", "Нет ребра:(");
    }
}


void MainWindow::on_but_save_clicked()
{
    QString name = ui->save->text();
    if(name.size() < 5){
        QMessageBox::warning(this, "Ошибка", "Файл должн оканчиватся на .txt .json .txt");
        return;
    }
    if (!((name.size()> 4 && name[name.size()-1] =='t' && name[name.size()-3] =='t'&& name[name.size()-2] =='x' && name[name.size()-4] == '.') ||(name.size()> 4 && name[name.size()-1] =='l' && name[name.size()-3] =='x' && name[name.size()-2] =='m' && name[name.size()-4] == '.')
            || (name.size()> 5 && name[name.size()-1] =='n' && name[name.size()-3] =='s'&& name[name.size()-2] =='o' && name[name.size()-5] == '.' && name[name.size()-4] =='j'))){
        QMessageBox::warning(this, "Ошибка", "Файл должн оканчиватся на .txt .json .txt");
        return;
    }
    std::string name_s = name.toLocal8Bit().constData();
    std::ofstream fout;
    fout.open(name_s);
    if (fout.is_open() == false){
        QMessageBox::warning(this, "Ошибка", "Не удается открыть файл");
        return;
    }
    fout << del.size() << std::endl;
    for (auto iter = del.begin(); iter != del.end(); iter++){
        std::string name_uz = (*iter)->name.toLocal8Bit().constData();
        int x = (*iter)->pos().toPoint().x();
        int y = (*iter)->pos().toPoint().y();
        fout << "<" << name_uz <<"> pos(" << x << ";" << y << ")" << std::endl;
    }
    fout << par.size() << std::endl;
    for(auto iter = del.begin(); iter != del.end(); iter++){
        for(auto j = par[(*iter)].begin(); j != par[(*iter)].end(); j++){
            std::string fir = (*iter)->name.toLocal8Bit().constData();
            std::string sec = (*j).first->name.toLocal8Bit().constData();
            fout << fir << " <-> " << sec << " " << (*j).second << std::endl;
        }
    }
}


void MainWindow::on_but_change_clicked()
{
    QString old = ui->old->text();
    QString new_ = ui->new_2->text();
    auto it = del.find(old);
    if(it == del.end()){
        QMessageBox::warning(this, "Ошибка", "Узла с названием " + old + " нет");
        return;
    }
    if (old == new_){
        return;
    }
    it = del.find(new_);
    if(it != del.end()){
        QMessageBox::warning(this, "Ошибка", "Eptk с названием " + old + " уже существует");
        return;
    }
    del[old]->name = new_;
    del[new_] = del[old];
    it = del.find(old);
    del.erase(it);
}


void MainWindow::on_but_down_clicked()
{
    QString name = ui->down->text();
    if(name.size() < 5){
        QMessageBox::warning(this, "Ошибка", "Файл должн оканчиватся на .txt .json .txt");
        return;
    }
    if (!((name.size()> 4 && name[name.size()-1] =='t' && name[name.size()-3] =='t'&& name[name.size()-2] =='x' && name[name.size()-4] == '.') ||(name.size()> 4 && name[name.size()-1] =='l' && name[name.size()-3] =='x' && name[name.size()-2] =='m' && name[name.size()-4] == '.')
            || (name.size()> 5 && name[name.size()-1] =='n' && name[name.size()-3] =='s'&& name[name.size()-2] =='o' && name[name.size()-5] == '.' && name[name.size()-4] =='j'))){
        QMessageBox::warning(this, "Ошибка", "Файл должн оканчиватся на .txt .json .txt");
        return;
    }
    std::string name_s = name.toLocal8Bit().constData();
    std::ifstream fin;
    fin.open(name_s);
    if (fin.is_open() == false){
        QMessageBox::warning(this, "Ошибка", "Не удается открыть файл");
        return;
    }
    QMap<std::string, QList<std::pair<std::string, int>>> par_new;
    QMap<std::string ,std::pair<int, int>> del_new;
    if (fin.eof()){
        QMessageBox::warning(this, "Ошибка", "Файл пуст");
        return;
    }
    std::string e;
    fin >> e;
    for (int i = 0; i < e.size(); i++){
            if( e[i] < '0' || e[i] > '9'){
                QMessageBox::warning(this, "Ошибка", "Нет колличества узлов в файле");
                return;
            }
    }
    QString Qe = QString::fromStdString(e);
    int size = Qe.toInt(), j = 0;
    for (int i = 0; i < size && !fin.eof(); i++){
        std::getline(fin, e);
        if (e.size() == 0 || e[0] != '<'){
            QMessageBox::warning(this, "Ошибка", "Файл не корректен");
            del_new.clear();
            par_new.clear();
            return;
        }
        std::string name_uz = "";
        for (j = 1; j < e.size() && e[j] != '>'; j++){
            name_uz += e[j];
        }
        if (j == e.size()){
            QMessageBox::warning(this, "Ошибка", "Файл не корректен");
            del_new.clear();
            par_new.clear();
            return;
        }
        j++;
        int x = 0, y = 0;
        if (e.size() < j + 8 || (e[j+1] != 'p' || e[j+2] != 'o' || e[j+3] != 's' || e[j+4] != '(')){
            QMessageBox::warning(this, "Ошибка", "Файл не корректен");
            del_new.clear();
            par_new.clear();
            return;
        }
        j += 5;
        for (j;j < e.size() && e[j]!=';'; j++){
            if(e[j] < '0' || e[j] > '9'){
                QMessageBox::warning(this, "Ошибка", "Файл не корректен");
                del_new.clear();
                par_new.clear();
                return;
            }
            x = x*10 + e[j] - '0';
        }
        if (e.size() == j || e[j-1] == '('){
            QMessageBox::warning(this, "Ошибка", "Файл не корректен");
            del_new.clear();
            par_new.clear();
            return;
        }
        for (j;j < e.size() && e[j]!=')'; j++){
            if(e[j] < '0' || e[j] > '9'){
                QMessageBox::warning(this, "Ошибка", "Файл не корректен");
                del_new.clear();
                par_new.clear();
                return;
            }
            y = y*10 + e[j] - '0';
        }
        if(j != e.size()-1){
            QMessageBox::warning(this, "Ошибка", "Файл не корректен");
            del_new.clear();
            par_new.clear();
            return;
        }
        auto it = del_new.find(name_uz);
        if(it != del_new.end()){
            QMessageBox::warning(this, "Ошибка", "Узел с именем " + name + " повторяется");
            del_new.clear();
            par_new.clear();
            return;
        }
        del_new[name_uz]= {x, y};
    }
}

