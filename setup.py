import setuptools

setuptools.setup(
    name="fast_inv_sqrt_c",
    version="0.1.1",
    description="A C Implementation on fast inverse square root",
    packages=setuptools.find_packages("src"),
    package_dir={"": "src"},
    ext_modules=[
        setuptools.Extension(
            "fast_inv_sqrt",
            sources=[
                "src/fast_inv_sqrt.c",
            ],
        )
    ],
)
