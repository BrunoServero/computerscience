package com.carros;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

import com.carros.controller.CarroController;
import com.carros.entity.Carro;

@SpringBootApplication
//   - Modelo, Marca, Ano Fab, Ano Modelo, Km, Preço, Cor, Lista Acessórios
public class CarrosServerApplication {

	public static void main(String[] args) {


		SpringApplication.run(CarrosServerApplication.class, args);
	}

}
