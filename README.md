#Reactor
###Musicals clothing made out of stretch knitted fabric sensor

S’habiller avec des vêtements technologiques c’est stylé ! c’est un jeu comme le cosplay, une manière d’incarner son temps dans une mixité des influences passées, présentes et futures. Les vêtements interactifs et musicaux que nous imaginons pourraient s’inscrire dans une démarche artistique et performative mais nous avons simplement choisi de nous adresser à des personnes qui souhaitent porter ce qu’on pourrait appeler un parfum sonore.

Le projet Reactor permet d’imaginer une multitude de modèles de vêtements instruments et articles sonores basés sur un principe de tricot capteur. Tricoté à la main à partir de fils de laine et de fils conducteurs, la maille permet ainsi de capter l’élongation, la tension du tissu ainsi que les plis et contacts de la matière pour déclencher ou contrôler des sons. Une attention particulière est portée à l’intégration du dispositif électronique qui disparaît totalement au profit d’une esthétique simple. Projet intergénérationnel, ce projet est aussi un prétexte pour organiser des ateliers avec des grand mères branchées qui pourront remettre le tricot au goût du jour.

C’est aussi pour solliciter des gestes que le vêtement est augmenté d’un parfum sonore, rendu réactif grâce à l’intégration d’une petite carte électronique le tricot adopte un nouveau statut d’objet instrument, la fonction musicale du vêtement entraine alors l’apprentissage d’une gestuelle particulière.

###Scénario N°1 : suivi de partition
A chaque fois que l’on bouge, presse ou plie le tricot, on "avance" d’une note dans une mélodie. Le rythme de cette mélodie correspond ainsi au rythme du mouvement de celui ou celle qui porte le vêtement et la composition fonctionne en boucle.
###Scénario N°2 : aléatoire contrôlé
Nous choisissons ici de distinguer plusieurs typologies de mouvement calme, en marche, excité, etc. Chacune de ces typologies est déterminée par la fréquence des mouvements captés. Plus on s’excite, plus les sons déclenchés sont aigus et distordus, à l’inverse, plus on est calme et plus les sons se réduisent à une sonorité simple.
###Scénario N°3 : le son extensible
Le stress exercé sur le tricot est générateur d’un son qui varie en relation directe avec l’étirement de la matière, plus le tricot est tendu plus le son est aigu. L’onde sonore est générée par synthèse. Une carte électronique dédiée permet de programmer plusieurs types de sons qui se rapprochent des sons 8-bit. Cette orientation fera l’objet d’une mise au point ultérieure car vous avons souhaité privilégier dans un premier temps une solution qui utilise des samples.
###Scénario N°4 : le son polyphonique
Dans ce dernier scénario le son sera généré par un téléphone portable assisté d’un mini système son. Ce téléphone sera aussi équipé d’une application musicale contrôlée par le vêtement. Pour réaliser un premier prototype nous avons choisi de travailler avec le système Android et donc d’aborder le développement d’une application en Java...

##Electronic
Pull on the knit cause resistor drop down. A voltage divider circuit is used to convert resistor variation into voltage value (Vs). This is done by adding a single 10K resistor (R2). To reduce power consumption of the voltage divider, the circuit is supplied (VCC) with a digital IO pin that allow on/off switching.The sketch is also implementing sleep mode.

![alt tag](https://farm9.staticflickr.com/8610/16594983667_a701634597_z_d.jpg)

The first prototype was using an ATTiny85 and a SOMO-4D (embedded audio-sound module) into an stand alone audio player electronic board made for a knitted fabric sensor. [This tutoriel explain how to program ATTiny with Arduino](http://hlt.media.mit.edu/?p=1229)

##TODO
- Translate in english the text project
- Replace the SOMO with less expensive module
 - [Teensy could be a good solution](https://www.pjrc.com/teensy/teensy31.html)
