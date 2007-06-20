#ifndef INCREMENTAL_ENGINE_HH
# define INCREMENTAL_ENGINE_HH

# include "../sliq/engine.hh"
# include "node.hh"

# define EXPERT_FREQUENCY   200


// Dans un noeud, on ajoute les informations suivantes:
//    - le nombre d'erreurs d�tect�es pass�es par l� PAR CLASSE
//    - le nombre d'enregistrements pass�s par l� PAR CLASSE
//    - L'age du noeud (en milliseconde)
//    -

typedef std::vector<int>    Example;

namespace   Incremental_sliq
{

class  Engine : public Sliq::Engine
{
public:
    // Constructeur
    Engine (std::string config_filename, std::vector<std::vector<int> > *examples);
    Example     &generate_data ();
    Sliq::Node    *init_node(int id, int nb_classes);
    // Retourne le num�ro de la classe de ex
    int         get_class(Example &ex);
    // Verifie que ex est bien dans classe, sinon l'ajoute dans le log d'erreur
    void        verify(Example ex, int classe);
    // Retourne le log d'erreur
    std::vector<Example>    &error_log_get () {return error_log_;};
    // Test un vecteur d'exemples et �crit les infos
    void        test(std::vector<Example> data);
    // Lance l'utilisation incr�mentale
    void        run_sliq_incremental();
    // Maj l'arbre avec l'erreur pass�e en param
    void        update_tree_with_errors();
    //
protected:
    // Liste des exemples mal class�s
    std::vector<Example>    error_log_;
};

}
#endif
