Implementace hry PacMan proti počítači.
===================================================


===== Základní funkcionality: =====

* Dodržování základních pravidel, sbírání bonusů, bodů (teček), třešniček.
* Je implementováno několik druhů AI duchů (fungující i zároveň).
    Těmi jsou náhodný pohyb, pronásledování hráče, cesta zpátky domů a nadběhnutí hráče.
* Lze načítat mapy ze souboru (včetně pozic bonusů, duchů a pacmana).

--- Základní formát mapy: ---

    ****************************
    *            **      G     *
    * **** ***** ******** ******
    *.                         *
    *.**** ** ******** ** **** *
    *.                         *
    *.**** ** ******** ** **** *
    *.                         *
    *.**** ***** ** ***** **** *
    *..... ..... **            *
    * **** ***** ******** ******
    *.                        %*
    *.**** ** ******** ** **** *
    *.           C             *
    *.**** ** ******** ** **** *
    *.                         *
    *.**** ***** ** ***** **** *
    *%.... ..... **           %*
    ****************************
>    
    * = hranice
    " " = prázdné políčko
    % = bonus
    . = bod
    C = počáteční pozice PacMana
    G = počáteční pozice duchů

* Konfigurovatelná obtížnost hry ze souboru (základní mód, počáteční obtížnost, rychlost duchů, délka trvání jednotlivých módů hry, pravděpodobnost přidání nového bonusu do mapy).

--- Základní formát nastavení: ---

    Difficulty: MEDIUM # Possible options: EASY | MEDIUM | HARD
    GameMode: NORMAL # Possible options: NORMAL | INVINCIBLE | CRAZY


===== Využití polymorfismu: =====

Herní plocha: Hranice, Prázdné políčko, Bonus, Třešnička, Bod
Rozdělení hráčů: PacMan, Duch
Typy chování: Náhodné, Pronásledující, Cesta zpátky domů, Nadběhnutí hráče
Módy hry: Normální, Nesmrtelný (duchové se dají zabít), Mód cesty domů, Šílený (pronásledování všemi duchy)


Jako uživatelské rozhraní je použitá konzole. Hra se ovládá šipkami, případně písmenky pro pohyb v menu.