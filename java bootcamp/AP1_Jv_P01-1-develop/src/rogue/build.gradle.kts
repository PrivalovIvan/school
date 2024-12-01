plugins {
    id("java")
}

group = "P1"
version = "1.0-SNAPSHOT"

repositories {
    mavenCentral()
}

dependencies {
    testImplementation(platform("org.junit:junit-bom:5.10.0"))
    testImplementation("org.junit.jupiter:junit-jupiter")
    // https://mvnrepository.com/artifact/org.projectlombok/lombok
    compileOnly("org.projectlombok:lombok:1.18.34")
    annotationProcessor("org.projectlombok:lombok:1.18.34")
    // https://mvnrepository.com/artifact/com.googlecode.lanterna/lanterna
    implementation("com.googlecode.lanterna:lanterna:3.1.2")
    //https://mvnrepository.com/artifact/com.fasterxml.jackson.core/jackson-databind/2.18.1
    implementation("com.fasterxml.jackson.core:jackson-databind:2.18.1")
}

tasks.test {
    useJUnitPlatform()
}