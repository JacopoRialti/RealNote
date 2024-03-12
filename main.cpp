#include <iostream>
#include "Note.h"
#include "Collection.h"
#include "Starred.h"

int main() {
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
    std::cout << "Rimuovo la nota  dalla collezione" << std::endl;
    volo_porto.removeNoteFromCollection(1);
    volo_porto.showCollection();
    std::cout << "\n\n";
    std::cout << "Provo a modificare la nota 'comprare', che non verra' modificata poiche' e' bloccata" << std::endl;
    nota_volo->setLocked(true);
    std::string w = "Modifica nota_volo";
    nota_volo->modifiyNote(w, w);
    volo_porto.showCollection();
    std::cout << "\n\n";
    //Grazie al design pattern Observer se elimino una nota, questa viene eliminata anche nella collezione
    std::cout << "Elimino la nota 'comprare volo, ma bloccata" << std::endl;
    nota_volo->deleteNote();
    volo_porto.showCollection();
    std::cout << "\n\n";
    nota_volo->setLocked(false);
    std::cout << "Elimino la nota 'comprare volo, non bloccata" << std::endl;
    nota_volo->deleteNote();
    volo_porto.showCollection();
    std::cout << "\n\n";
    volo_porto.addNoteToCollection(nota_bagaglio);
    std::cout << "Modifico la nota 'bagaglio' " << std::endl;
    std::string z = "Modifica nota_bagaglio";
    nota_bagaglio->modifiyNote(z,z);
    volo_porto.showCollection();
    std::cout << "\n\n";

    Note *note1 = new Note("Note 1", "This is note 1");
    Note *note2 = new Note("Note 2", "This is note 2");
    Note *note3 = new Note("Note 3", "This is note 3");
    Starred *starred = Starred::getInstance();
    starred->addNoteToCollection(note1);
    starred->addNoteToCollection(note2);
    starred->addNoteToCollection(note3);
    starred->showCollection();
    std::cout << "\n\n";
    starred->removeNoteFromCollection(0);
    starred->showCollection();

    return 0;
}
