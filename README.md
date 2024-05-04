Rapport sur le code :
Le code que je vous présente est un programme de gestion de bibliothèque écrit en langage C. Il vous permet d'effectuer différentes opérations, comme afficher, ajouter, supprimer et rechercher des livres dans une bibliothèque. De plus, il offre la possibilité de sauvegarder les détails des livres dans un fichier texte.

Fonctions utilisées :
displayBook : Cette fonction affiche les détails d'un livre donné sur la console.
displayBookToFile : Cette fonction enregistre les détails d'un livre donné dans un fichier texte.
InsertData : Cette fonction vous permet d'insérer les détails des livres dans la bibliothèque en saisissant les informations via la console.
AddBook : Cette fonction ajoute un nouveau livre à la bibliothèque en vous demandant de saisir ses détails via la console.
DeleteBook : Cette fonction supprime un livre de la bibliothèque en fonction de sa position dans la liste.
SearchByTitle : Cette fonction recherche et affiche les livres ayant un titre donné.
SearchByAuthor : Cette fonction recherche et affiche les livres écrits par un auteur donné.
sortBooksByTitle : Cette fonction trie les livres dans la bibliothèque par titre dans l'ordre alphabétique.
sortBooksByCategory : Cette fonction trie les livres dans la bibliothèque par catégorie dans l'ordre alphabétique.

Explication du code :
Le programme commence par vous demander votre identité et le nombre de livres que vous souhaitez ajouter à la bibliothèque. Ensuite, il alloue de la mémoire pour stocker les détails des livres.

Ensuite, le programme affiche un menu interactif qui vous permet d'effectuer différentes opérations sur la bibliothèque, comme afficher tous les livres, ajouter un nouveau livre, supprimer un livre, rechercher des livres par titre ou auteur, et trier les livres par titre ou catégorie.

Les fonctions sont conçues pour être modulaires et réutilisables, ce qui permet une gestion efficace de la bibliothèque. Les détails des livres sont stockés dans des structures de données définies par l'utilisateur, ce qui facilite la manipulation et l'organisation des informations.

Enfin, le programme se termine lorsque vous choisissez l'option de quitter, et tous les livres affichés sont également sauvegardés dans un fichier texte pour une référence ultérieure.
