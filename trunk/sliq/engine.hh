#ifndef ENGINE_HH
# define ENGINE_HH

# include <iostream>
# include <string>
# include <vector>
# include "node.hh"
# include "attribute.hh"

namespace Sliq
{
    // Contient les donn�es, les fonctions d'inialisation
    // et les fonctions de lancement de construction de l'arbre
    class Engine
    {
    public:
        // Constructeur
        Engine () {};
        Engine (std::string config_filename, std::vector<std::vector<int> > *examples);
        virtual Node    *init_node(int id, int nb_classes);
        // Charge les exemples d'un fichier
        std::vector<std::vector<int> >    &load_examples(std::string &filename);

        // Cr�e les listes d'attributs � partir d'une ensemble d'exemples
        // ne sert � rien �galement je pense
        // bool    compute_attribute_lists (std::vector<Example> examples);
        // Construit l'arbre de racine tree
        bool    compute_sliq ();
        Node    *tree_get () {return tree_;}
        // Met � jour les histogrammes de toutes les feuilles temporaires
        // pour l'attribut pass� en param�tre
        // Les meilleurs tests sont conserv�s au fur et � mesure
        void   Engine::update_histograms (int attribut);
        // Retourne le num�ro de la classe de l'exemple ex
        int    classify(std::vector<int> ex);

    protected:
        // liste de tous les noeuds de l'arbre
        // sert � rien finalement
        // std::map<int, Node*>                nodes;
        // Class list
        // Associe � chaque index d'exemple (l'indice) l'index d'une classe
        // et un noeud (son indice dans la map)
        std::vector<std::pair<int, Node*> > class_list_;
        // Liste des attributs (associe un nom � chaque num�ro d'attribut)
        std::vector<std::string>            attribute_names_;
        // Liste des classes (associe un nom � chaque num�ro de classe)
        std::vector<std::string>            classes_names_;
        // Liste des attribute_list (associ� au num�ro d'attribut)
        std::vector<Attribute::List>        attribute_lists_;
        // Racine de l'arbre cr�� � partir des exemples
        Node                                *tree_;
    };
}

std::ostream    &operator<<(std::ostream &os, Sliq::Engine &engine);

#endif
