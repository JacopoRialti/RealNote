#include <iostream>
#include "src/Note.h"
#include "src/Collection.h"
#include "src/Starred.h"

int main()
{
    Note *nota_volo = new Note("Compare Volo", "Scegliere migliore data per viaggiare");
    Note *nota_bagaglio = new Note("Bagaglio", "Spazzolino, mutande");
    Collection volo_porto("Volo Porto");
    volo_porto.showCollection();
    std::cout << "\n\n";

    std::cout << "Aggiungo le note alla collezione Volo Porto" << std::endl;
    volo_porto.addNoteToCollection(nota_volo);
    volo_porto.addNoteToCollection(nota_bagaglio);
    volo_porto.showCollection();
    std::cout << "\n\n";

    std::cout << "Rimuovo la nota Bagaglio dalla collezione" << std::endl;
    volo_porto.removeNoteFromCollection(1);
    volo_porto.showCollection();
    std::cout << "\n\n";

    std::cout << "Provo a modificare la nota 'comprare', che non verra' modificata poiche' e' bloccata" << std::endl;
    nota_volo->setLocked(true);
    std::string w = "Modifica nota_volo";
    nota_volo->modifiyNote(w, w);
    volo_porto.showCollection();
    std::cout << "\n\n";

    std::cout << "Provo ad eliminare la nota 'comprare volo', ma bloccata" << std::endl;
    nota_volo->deleteNote();
    volo_porto.showCollection();
    std::cout << "\n\n";

    nota_volo->setLocked(false);
    std::cout << "Elimino la nota 'comprare volo., non bloccata" << std::endl;
    nota_volo->deleteNote();
    volo_porto.showCollection();
    std::cout << "\n\n";

    volo_porto.addNoteToCollection(nota_bagaglio);
    std::cout << "Riaggiungo e modifico la nota 'bagaglio' " << std::endl;
    std::string z = "Modifica nota_bagaglio";
    nota_bagaglio->modifiyNote(z,z);
    volo_porto.showCollection();
    std::cout << "\n\n";

    std::cout << "Creo una collezione di note 'Starred' e aggiungo delle note" << std::endl;
    Note *note1 = new Note("Note 1", "This is note 1");
    Note *note2 = new Note("Note 2", "This is note 2");
    Note *note3 = new Note("Note 3", "This is note 3");
    Starred *starred = Starred::getInstance();
    starred->addNoteToCollection(note1);
    starred->addNoteToCollection(note2);
    starred->addNoteToCollection(note3);
    starred->showCollection();
    std::cout << "\n\n";
    std::cout << "Rimuovo la note 1 dalla collezione" << std::endl;
    starred->removeNoteFromCollection(0);
    starred->showCollection();
    return 0;
}
