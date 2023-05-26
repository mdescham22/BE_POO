# BE Programmation Orienté Objet
## Bracelet détecteur de chute
### Implémentation
Ouvrez le fichier "CodeFinal.ino" et configurez la carte NodeMCU 1.0 ainsi que le port sur lequel elle est connectée. Implémentez ensuite le programme sur la carte.
### Utilisation
Utilisez le détecteur cardiaque et appuyez sur le bouton. À ce moment-là, le programme détectera la présence d'une chute. Si une chute est détectée mais qu'elle est sans danger, vous avez la possibilité de l'annuler dans les 5 secondes en appuyant sur le bouton. Dans le cas contraire, le piezo émettra un son d'alarme pour alerter les personnes aux alentours et tenter de vous réveiller en cas de perte de conscience. Vous aurez toujours la possibilité de stopper l'alarme en appuyant sur le bouton. Si le pouls n'est plus détecté, le système considérera que vous faites un arrêt cardiaque et émettra une alarme différente avec le son d'alarme du piezo.
