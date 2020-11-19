package com.carros.controller;

import org.springframework.web.bind.annotation.*;

import com.carros.entity.Carro;

@RestController
public class CarroController<i> {

    Carro carros[] = new Carro[20];
    int ids[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    String modelos[] = {"Fusca","Corsa","Classic", "Brasilia", "Civic", "Celta", "Palio", "Focus", "Fox", "Cross Fox", "HB20", "Fiesta", "KA", "Ecosport", "350z", "DB5", "Lancer", "Fit", "Cobalt", "Versailles" };
    String marcas[] = {"Volks", "Chevrolet", "Chevrolet", "Volks", "Honda", "Chevrolet", "Fiat", "Ford", "Volks", "Volks", "Hyundai", "Ford", "Ford", "Ford", "Nissan", "Aston Martin", "Mitsubishi", "Honda", "Chevrolet", "Ford"};
    int anoFab[] = {1973,2002, 2007, 1975, 2010, 2010, 2010, 2012, 2010, 2011, 2020, 2012, 2013, 2015, 2005, 1964, 2018, 2007, 2016, 1995};
    int anoMod[] = {1974,2003, 2008, 1976, 2011, 2011, 2011, 2013, 2011, 2012, 2021, 2013, 2014, 2016, 2006, 1965, 2019, 2008, 2017, 1996};
    int km[] = {100000, 50000, 300, 200000, 10000, 70000, 45000, 80000, 120000, 150000, 10000, 40000, 35000, 60000, 5000, 8000, 35000, 40000, 35000, 70000 };
    int preco[] = {30000, 11900, 15900, 25000, 37890, 18900, 19900, 28999, 21990, 21900, 53990, 26970, 38940, 27900, 150000, 18000000, 273990, 49990, 46900, 11500};
    String cor[] = {"Bege", "Cinza", "Azul", "Amarela", "Cinza", "Vermelho", "Azul-Marinho", "Prata", "Vermelho", "Prata", "Cinza", "Branco", "Vermelho", "Preto", "Preto", "Prata", "Azul", "Prata", "Preto", "Azul" };
    String listAcess[] = {"trata/alarme","vidro eletrico, trava, ar condicionado, alarme",
            "vidro eletrico, trava, ar condicionado, alarme" , "trava/alarme", "vidro eletrico, trava, ar condicionado, alarme" ,
            "vidro eletrico, trava, ar condicionado, alarme" ,"vidro eletrico, trava, ar condicionado, alarme" ,
            "vidro eletrico, trava, ar condicionado, alarme" ,"vidro eletrico, trava, ar condicionado, alarme" ,
            "vidro eletrico, trava, ar condicionado, alarme" ,"vidro eletrico, trava, ar condicionado, alarme" ,
            "vidro eletrico, trava, ar condicionado, alarme" ,"vidro eletrico, trava, ar condicionado, alarme" ,
            "vidro eletrico, trava, ar condicionado, alarme" ,"vidro eletrico, trava, ar condicionado, alarme" ,
            "vidro eletrico, trava, ar condicionado, alarme" ,"vidro eletrico, trava, ar condicionado, alarme" ,
            "vidro eletrico, trava, ar condicionado, alarme" ,"vidro eletrico, trava, ar condicionado, alarme" ,
            "vidro eletrico, trava, ar condicionado, alarme" };

    public void preencheCarros(){
        for(int i = 0; i<20; i++){
            Carro car = new Carro(ids[i], modelos[i], marcas[i], anoFab[i], anoMod[i], km[i],
                    preco[i], cor[i], listAcess[i]);
            carros[i] = car;
        };

    }

    @GetMapping("/carros")
    public String getAllCarros() {
        preencheCarros();
        String response = null;
        for (int i = 0; i < 20; i++) {

            response +=  "ID -->" + carros[i].getId() + "\n" +
                    "Modelo -->" + carros[i].getModelo() + "\n" +
                    "Marca -->" + carros[i].getMarca() + "\n" +
                    "AnoFab -->" + carros[i].getAnoFab() + "\n" +
                    "AnoMod -->" + carros[i].getAnoMod() + "\n" +
                    "KM -->" + carros[i].getKm() + "\n" +
                    "Preço -->" + carros[i].getPreco() + "\n" +
                    "Cor -->" + carros[i].getCor() + "\n" +
                    "Acessorios -->" + carros[i].getListaAcessorio() + "\n\n";
        }
        return response;
    }
	@GetMapping("/carro")
    public String getCarroByID(@RequestParam int ID){
        preencheCarros();
        return  "Modelo -->" + carros[ID].getModelo() + "\n" +
                "Marca -->" + carros[ID].getMarca() + "\n" +
                "Preço -->" + carros[ID].getPreco() + "\n\n";
    }
	@GetMapping("/carro/all")
    public String getCarroByIDAll(@RequestParam int ID, @RequestParam(value="info", required = false)String info) {
        preencheCarros();

        return "ID -->" + carros[ID].getId() + "\n" +
                "Modelo -->" + carros[ID].getModelo() + "\n" +
                "Marca -->" + carros[ID].getMarca() + "\n" +
                "AnoFab -->" + carros[ID].getAnoFab() + "\n" +
                "AnoMod -->" + carros[ID].getAnoMod() + "\n" +
                "KM -->" + carros[ID].getKm() + "\n" +
                "Preço -->" + carros[ID].getPreco() + "\n" +
                "Cor -->" + carros[ID].getCor() + "\n" +
                "Acessorios -->" + carros[ID].getListaAcessorio() + "\n\n";

    }
    @GetMapping("/carros/filter/precomaior")
    public String getCarrosMaiorPreco(@RequestParam(value="maior", required = false) int info){
        preencheCarros();
        String response = "";
        for (int i =0; i<20; i++){
            if (carros[i].getPreco() >= info){
                response += "ID -->" + carros[i].getId() + "\n";
            }
        }
        return response;
    }

    @GetMapping("/carros/filter/precomenor")
    public String getCarrosMenorPreco(@RequestParam(value="menor", required = false) int info){
        preencheCarros();
        String response = "";
        for (int i =0; i<20; i++){
            if (carros[i].getPreco() <= info){
                response += "ID -->" + carros[i].getId() + "\n";
            }
        }
        return response;
    }

    @GetMapping("/carros/filter/km")
    public String getCarrosMenorKM(@RequestParam(value="menor", required = false) int info){
        preencheCarros();
        String response = "";
        for (int i =0; i<20; i++){
            if (carros[i].getKm() <= info){
                response += "ID -->" + carros[i].getId() + "\n";
            }
        }
        return response;
    }

    @GetMapping("/soma/{n1}+{n2}")
    public String getSomaNumeros(@PathVariable(value="n1") int n1, @PathVariable(value="n2") int n2){
        return String.valueOf(n1+n2);
    }
}
