# PetSalut: Xarxa Social per a Animals

**PetSalut** és una aplicació web que actua com una xarxa social per a mascotes, propietaris i clíniques veterinàries. Aquesta aplicació permet gestionar de manera eficient usuaris (propietaris i clíniques), mascotes, esdeveniments públics i visites privades, oferint una experiència unificada i funcional per a tots els participants.

---

## Característiques Principals

### 1. Gestió de Base de Dades
- **Base de dades robusta i optimitzada** desenvolupada amb MySQL Workbench.
- Suport per a entitats com:
  - Propietaris i clíniques veterinàries.
  - Mascotes i els seus tipus específics.
  - Centres associats a les clíniques, amb especialitzacions.
  - Esdeveniments (públics i privats) i valoracions.

### 2. Funcionalitats CRUD
L'aplicació permet operacions bàsiques de creació, lectura, actualització i eliminació (CRUD) per a:
- Propietaris.
- Mascotes.
- Clíniques i centres.

### 3. Esdeveniments Públics i Privats
- **Esdeveniments públics:**
  - Funcionalitat de "feed" per veure informació detallada.
  - Inscripció i cancel·lació d'esdeveniments per part dels usuaris.
  - Creació d'esdeveniments públics per fomentar la participació comunitària.
- **Esdeveniments privats (visites):**
  - Permeten que els usuaris programin visites amb centres especialitzats.
  - Inclouen un sistema de valoracions per oferir feedback als centres.

### 4. Interfície d'Usuari
- **Interfície compartida** per a clíniques i propietaris, que millora l'accessibilitat i facilita l'inici de sessió.
- **Disseny coherent i interactiu**:
  - Navegació intuïtiva.
  - Experiència visual més agradable.

---

## Desafiaments i Solucions

Durant el desenvolupament de PetSalut, ens vam trobar amb diversos desafiaments, entre els quals destaquen:
1. **Falta inicial de planificació de la base de dades:**  
   Vam ajustar el diagrama de classes per millorar-ne l'estructura i la funcionalitat, garantint una gestió de dades més eficient.
   
2. **Problemes amb la classe de connexió:**  
   Vam refactoritzar la classe, assegurant una comunicació estable entre l'aplicació i la base de dades.

3. **Falta d'integració:**  
   Vam redefinir les històries d'usuari i vam implementar proves integrades per completar funcionalitats de manera satisfactòria.

---

## Requisits del Sistema

Per executar PetSalut, es necessiten els següents requisits:
- **Entorn de Desenvolupament**:
  - MySQL Workbench per gestionar la base de dades.
  - IDE per a aplicacions web (com IntelliJ IDEA o Eclipse).
- **Dependències**:
  - Connector JDBC per a la comunicació entre l'aplicació i MySQL.
  - Llibreries per al frontend (HTML, CSS, JavaScript).

---
