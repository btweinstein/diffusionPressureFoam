    Info<< "Reading field T\n" << endl;

    volScalarField c
    (
        IOobject
        (
            "c",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ,
            IOobject::AUTO_WRITE
        ),
        mesh
    );

    volScalarField P
    (
        IOobject
        (
            "P",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ,
            IOobject::AUTO_WRITE
        ),
        mesh
    );

    Info<< "Reading transportProperties\n" << endl;

    IOdictionary transportProperties
    (
        IOobject
        (
            "transportProperties",
            runTime.constant(),
            mesh,
            IOobject::MUST_READ_IF_MODIFIED,
            IOobject::NO_WRITE
        )
    );

    Info<< "Reading diffusion constant D\n" << endl;

    dimensionedScalar D
    (
        transportProperties.lookup("D")
    );

    Info<< "Reading base density of the media rho_0\n" << endl;

    dimensionedScalar rho_0
    (
        transportProperties.lookup("rho_0")
    );

    Info<< "Reading solute expansion coefficient beta \n" << endl;

    dimensionedScalar beta
    (
        transportProperties.lookup("beta")
    );

    #include "readGravitationalAcceleration.H"
