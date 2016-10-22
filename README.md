# Tricot Reactor

### Musicals clothing made out of stretch knitted fabric sensor

S’habiller avec des vêtements technologiques c’est stylé! c’est un jeu comme le cosplay, une manière d’incarner son temps dans la mixité des influences passées, présentes et futures. Les vêtements interactifs et musicaux que nous imaginons pourraient s’inscrire dans une démarche artistique et performative mais nous avons décidé de nous adresser à un public plus large. Augmenté d'un "parfum sonore" le tricot Reacor est une sorte de vetement instrument. Rendu réactif grâce à l’intégration d’une petite carte électronique, le tricot Reactor permet d’imaginer une multitude de modèles de vêtements instruments. Tricoté à la main à partir de fils de laine et de fils conducteurs, la maille permet ainsi de capter l’élongation, la tension du tissu ainsi que les plis et contacts de la matière pour déclencher ou contrôler des sons. Une attention particulière est portée à l’intégration de l'électronique qui disparaît totalement au profit d’une esthétique simple. Intergénérationnel, ce projet est aussi un prétexte pour organiser des ateliers avec des grand mères branchées qui pourront remettre leur tricot au goût du jour.

[![Tricot-Reactor](https://c1.staticflickr.com/8/7728/18238759816_af343857b1_z.jpg)](https://www.flickr.com/photos/maurin/18238759816/in/dateposted-public/ "Click to watch the video!")

## Scénarios

### Suivi de partition
A chaque fois que l’on bouge, presse ou plie le tricot, on "avance" d’une note dans une mélodie. Le rythme de cette mélodie correspond ainsi au rythme du mouvement de celui ou celle qui porte le vêtement et la composition fonctionne en boucle.

### Aléatoire contrôlé
Nous choisissons ici de distinguer plusieurs typologies de mouvement calme, en marche, excité, etc. Chacune de ces typologies est déterminée par la fréquence des mouvements captés. Plus on s’excite, plus les sons déclenchés sont aigus et distordus, à l’inverse, plus on est calme et plus les sons se réduisent à une sonorité simple.

### Le son extensible
Le stress exercé sur le tricot est générateur d’un son qui varie en relation directe avec l’étirement de la matière, plus le tricot est tendu plus le son est aigu. L’onde sonore est générée par synthèse. Une carte électronique dédiée permet de programmer plusieurs types de sons qui se rapprochent des sons 8-bit. Cette orientation fera l’objet d’une mise au point ultérieure car vous avons souhaité privilégier dans un premier temps une solution qui utilise des samples.

### Le son polyphonique
Dans ce dernier scénario le son sera généré par un téléphone portable assisté d’un mini système son. Ce téléphone sera aussi équipé d’une application musicale contrôlée par le vêtement. Pour réaliser un premier prototype nous avons choisi de travailler avec le système Android et donc d’aborder le développement d’une application en Java...

## Electronic
Pull on the knit cause resistor drop down. A voltage divider circuit is used to convert resistor variation into voltage value (Vs). This is done by adding a single 10K resistor (R2). To reduce power consumption of the voltage divider, the circuit is supplied (VCC) with a digital IO pin that allow on/off switching.The sketch is also implementing sleep mode.

![alt tag](https://farm9.staticflickr.com/8610/16594983667_a701634597_z_d.jpg)

The first prototype was using an ATTiny85 and a SOMO-4D (embedded audio-sound module) to build a small stand alone audio player. [This tutoriel explain how to program ATTiny with Arduino](http://hlt.media.mit.edu/?p=1229)

## TODO
- Translate the text in english
- Replace the SOMO with the [Teensy 3.2](https://www.pjrc.com/teensy/teensy31.html)
- Add a small amplifier
