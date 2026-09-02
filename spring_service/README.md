# DepthWizard Spring Boot Backend
This is the Spring Boot backend part of DepthWizard.

## Requirements
- Java 21+
- PostgreSQL

## Setup
- `git clone` this project. If the project is already cloned locally, `git pull` and then `git checkout` this branch.
- Under `src/resources` folder, set up an `application-local.properties` file which should contain the PostgreSQL database credentials. Follow the format in `application-local.properties.example`.
- Run `mvn clean install` (or `./mvnw clean install`) to install the dependencies.
- Run `mvn spring-boot:run` (or `./mvnw spring-boot:run`) to run this project.