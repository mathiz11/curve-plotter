#include <iostream>
#include <fstream>
#include <stdexcept>
#include <cmath>
#include <sstream>

using namespace std;

#include "Operator.hpp"
#include "ez-draw++.hpp"

class Traceur : public EZWindow
{
 Operator * op1;  // Les fonction du traceur
 Operator * op2;  //
 double xmin,xmax,ymin,ymax; // Les valeurs minimum et maximum de la fenetre de visibilite.
 unsigned short step;  // On tracera la fonction avec un point tous les pixel_step pixels.
 int curi,curj; // Les coordonnees du curseur d'exploration

 void trace_axes()
 {
  setColor(ez_black);
  unsigned int x0 = int ( (0.-xmin)/(xmax-xmin)*double(getWidth() -0) );
  unsigned int y0 = getHeight() - int ( (0.-ymin)/(ymax-ymin)*double(getHeight()-0) );
  if(y0 <= getHeight()-1) drawLine(0,y0,getWidth()-1,y0);  // Axe des X
  if(x0 <= getWidth() -1) drawLine(x0,0,x0,getHeight()-1); // Axe des Y
}

 void trace_fonction1()
 {
  setColor(ez_blue);
  int ipred,jpred; // Les coordonnees du point du tour de boucle precedant.
  for(unsigned int i=0;i<getWidth();i+=step)
   {
    double       x = double(i-0)*(xmax-xmin)/double(getWidth()-0) + xmin; // On calcule le x reel correspondant a la colonne de pixel i.
    double       y;
    try { y = (*op1)(x); } // On declenche la fonction *f sur la coordonnee x et on stocke la valeur dans y.
    catch(exception& e) { y = -1000; }

    int j;
    if     (y < ymin) j = getWidth(); // Si y est trop petit, on force j a la ligne du bas.
    else if(y > ymax) j = -1;         // Si y est trop grand, on force j a la ligne du haut.
    else              j = getHeight() - (unsigned int)( (y-ymin)*(getHeight()-0)/(ymax-ymin) - 0 );  // On calcule le j entier correspondant a la valeur de y.

    if(i==0) drawPoint(i,j);            // Si c'est le premier point, on met juste un point
    else     drawLine(ipred,jpred,i,j); // sinon on trace une ligne reliant le point precedant au point courant.
    ipred = i; jpred = j; // Memorisation de i et j pour le tour suivant.
   }
 }

 void trace_fonction2()
 {
  setColor(ez_green);
  int ipred,jpred; // Les coordonnees du point du tour de boucle precedant.
  for(unsigned int i=0;i<getWidth();i+=step)
   {
    double       x = double(i-0)*(xmax-xmin)/double(getWidth()-0) + xmin; // On calcule le x reel correspondant a la colonne de pixel i.
    double       y;
    try { y = (*op2)(x); } // On declenche la fonction *f sur la coordonnee x et on stocke la valeur dans y.
    catch(exception& e) { y = -1000; }

    int j;
    if     (y < ymin) j = getWidth(); // Si y est trop petit, on force j a la ligne du bas.
    else if(y > ymax) j = -1;         // Si y est trop grand, on force j a la ligne du haut.
    else              j = getHeight() - (unsigned int)( (y-ymin)*(getHeight()-0)/(ymax-ymin) - 0 );  // On calcule le j entier correspondant a la valeur de y.

    if(i==0) drawPoint(i,j);            // Si c'est le premier point, on met juste un point
    else     drawLine(ipred,jpred,i,j); // sinon on trace une ligne reliant le point precedant au point courant.
    ipred = i; jpred = j; // Memorisation de i et j pour le tour suivant.
   }
 }

 void trace_curseur()
 {
  setColor(ez_red);
  ostringstream oss;
  if(curi>=0 && curi<int(getWidth()) && curj>=0 && curj<int(getHeight()) ) // Si le curseur est dans la fenetre,
   {
    double x = double(curi-0)*(xmax-xmin)/double(getWidth()-0)  + xmin;
    double y = double(getHeight()-curj)*(ymax-ymin)/double(getHeight()-0) + ymin;
    const int cursor_size = 3;
    drawRectangle(curi-cursor_size,curj-cursor_size,curi+cursor_size,curj+cursor_size);
    oss << "x=" << x << " y=" << y;
   }
  else
   oss << "Cliquez pour mesurer une position.";
  drawText(EZAlign::BL,3,getHeight()-10,oss.str());
 }

public:

  Traceur(int w, int h, const char *name, Operator * _op1, Operator * _op2, double _xmin, double _xmax, double _ymin, double _ymax, unsigned short _step)
  : EZWindow(w,h,name),op1(_op1), op2(_op2), xmin(_xmin),xmax(_xmax),ymin(_ymin),ymax(_ymax),
    step(3), curi(-1),curj(-1)
  { setDoubleBuffer(true); }

  void expose()
  {
  clear();
  trace_axes();
  trace_curseur();
  trace_fonction1();
  if(op2 != nullptr)   // si op2 = nullptr, la fonction est cartesian sinon parametrique donc on trace la fonction2
    trace_fonction2();
  }

 void keyPress(EZKeySym keysym) // Une touche du clavier a ete enfoncee ou relachee
  {
   double xstep = (xmax-xmin)/10.;
   double ystep = (ymax-ymin)/10.;
    switch (keysym)
     {
        case EZKeySym::Escape:
        case EZKeySym::q :
          EZDraw::quit();
          break;
        case EZKeySym::Left:  xmin -= xstep; xmax-=xstep; sendExpose(); break;
        case EZKeySym::Right: xmin += xstep; xmax+=xstep; sendExpose(); break;
        case EZKeySym::Down:  ymin -= ystep; ymax-=ystep; sendExpose(); break;
        case EZKeySym::Up:    ymin += ystep; ymax+=ystep; sendExpose(); break;
        case EZKeySym::minus:
        case EZKeySym::KP_Subtract:
          xmin -= xstep; xmax+=xstep;
          ymin -= ystep; ymax+=ystep;
          sendExpose();
          break;
        case EZKeySym::plus:
        case EZKeySym::KP_Add:
          xmin += xstep; xmax-=xstep;
          ymin += ystep; ymax-=ystep;
          sendExpose();
          break;
        default: // Dans tous les autres cas on ne fait rien (nécessaire
          break; // pour éviter un warning à la compilation).
     }
  }

 void buttonPress(int i,int j,int/*button*/)
  { curi = i;  curj = j;  sendExpose(); }

 void motionNotify(int i,int j,int button)
  {
   if(button == 1) // Si le bouton gauche est enfonce seulement,
    { curi = i;  curj = j; sendExpose(); } // on met a jour l'affichage.
  }

 void buttonRelease(int /*i*/,int /*j*/,int /*button*/)
  { curi = -1; curj = -1; sendExpose(); }
};

//= La classe MyApplication dérivée de EZDraw =================================
class MyApplication : public EZDraw {
  Traceur win;
 public:
  MyApplication(const char * title, Operator * op1, Operator * op2,
                double xmin, double xmax, double ymin, double ymax, double step) // Constructeur MyApplication
  : win(640,480, title, op1, op2, xmin, xmax, ymin, ymax, step)
  {}
};

double max(Operator * o, double inf, double sup, unsigned int pad)    // Fonction retournant le point maximum d'une fonction par rapport à l'ordonnée (ymax)
{
  double maximum = o->evaluate(inf);         // le 1er point de la fonction est stocké dans maximum
  double step = fabs(sup - inf) / pad;       // le pas entre chaque point = valeur absolue de (xmax - xmin) / nombre d'echantillons
  for(double i = inf; i < sup; i += step)    // Parcours de la fonction
  {
    if(maximum < o->evaluate(i))             // on stock le point quand il est plus grand que le dernier enregistrer
      maximum = o->evaluate(i);
  }
  return maximum;   // renvoie du plus grand point
}

double min(Operator * o, double inf, double sup, unsigned int pad)    // Fonction retournant le point minimum d'une fonction par rapport à l'ordonnée (ymin)
{
  double minimum = o->evaluate(inf);       // le 1er point de la fonction est stocké dans minimum
  double step = fabs(sup - inf) / pad;     // le pas entre chaque point = valeur absolue de (xmax - xmin) / nombre d'echantillons
  for(double i = inf; i < sup; i += step)  // Parcours de la fonction
  {
    if(minimum > o->evaluate(i))           // on stock le point quand il est plus grand que le dernier enregistrer
      minimum = o->evaluate(i);
  }
  return minimum;   // renvoie du plus petit point
}

int main(int argc, char * argv[])
{
  if(argc == 1)
    cerr << "Erreur : Le programme a besoin d'au moins un fichier en parametre"
         << "pour fonctionner." << endl;
  else
  {
    
    string title, type, interval;
    double boundary_inf, boundary_sup; // initalisation des variables
    unsigned int pattern;

    for(int i = 1; i < argc; ++i)
    {
      ifstream monFlux(argv[i]);
      if(!monFlux)
        throw runtime_error("Le fichier saisi est introuvable ou corrompu"); 
      getline(monFlux, title);   // 1ere ligne du fichier stocké dans title
      monFlux >> type;           // 1ere chaine de caractère a partir de la ligne 2 stocké dans type (c'est le type de la fonction)
      monFlux >> boundary_inf;   // 2eme chaine, borne minimum (xmin)
      monFlux >> boundary_sup;   // 3eme chaine, borne maximum (cmax)
      monFlux >> pattern;        // 4eme chaine, l'expression

      double step = fabs(boundary_sup - boundary_inf) / pattern; // distance entre chaque point

      const char * titlec = title.c_str();  // conversion d'une string en const char *

      if(type == "cartesian")
      {
        Operator * pOperator = Operator::load(monFlux);
        double mini = min(pOperator, boundary_inf, boundary_sup, pattern) - step; // le point minimum de la fonction
        double maxi = max(pOperator, boundary_inf, boundary_sup, pattern) + step; // Le point maximum de la fonction
        MyApplication myapp(titlec, pOperator, nullptr, boundary_inf, boundary_sup,  // création de l'instance MyApplication avec tous les
                            mini, maxi, step);                                       // attributs servant à dessinner la fonction
        myapp.mainLoop(); //affichage de la fenetre
        delete pOperator; // delete car new
      }
      else if(type == "parametric")
      {
        Operator * pOperator1 = Operator::load(monFlux);
        Operator * pOperator2 = Operator::load(monFlux);
        double mini1 = min(pOperator1, boundary_inf, boundary_sup, pattern) - step;   // le point minimum de la 1ere fonction
        double maxi1 = max(pOperator1, boundary_inf, boundary_sup, pattern) + step;   // Le point maximum de la 1ere fonction
        double mini2 = min(pOperator2, boundary_inf, boundary_sup, pattern) - step;   // le point minimum de la 2ere fonction
        double maxi2 = max(pOperator2, boundary_inf, boundary_sup, pattern) + step;   // le point maximum de la 2ere fonction
        double mini = mini1;
        if(mini1 > mini2)        //  On gardera le plus petit ymin des deux fonction
          mini = mini2;          // pour avoir une fenetre prenant en compte les points les plus bas des 2 fonctions
        double maxi = maxi1;     // On gardera le plus grand ymax des deux fonction
        if(maxi1 < maxi2)        // pour avoir une fenetre prenant en compte les points les plus haut des 2 fonctions
          maxi = maxi2;
        MyApplication myapp(titlec, pOperator1, pOperator2, boundary_inf, boundary_sup, // création de l'instance MyApplication avec tous les
                            mini, maxi, step);                                          // attributs servant à dessinner la fonction
        myapp.mainLoop(); // affichage de la fenetre
        delete pOperator1;
        delete pOperator2; // delete des 2 Operators car new
      }
      else
        throw runtime_error("Le type de la fonction est inconnu."); // erreur si ligne 2 errroné
    }
  }
  return 0;
}
