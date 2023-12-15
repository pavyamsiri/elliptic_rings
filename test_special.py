"""Test special functions."""

from scipy import integrate
import numpy as np


def calculate_mu_scipy(
    mass: float, semi_minor_axis: float, ecc_squared: float
) -> float:
    mu = (
        mass
        / integrate.quad(
            lambda theta: semi_minor_axis
            / np.sqrt(1 - ecc_squared**2 * np.cos(theta) ** 2),
            0,
            2 * np.pi,
        )[0]
    )
    print(f"SciPy: Mu = {mu}")
    return mu


def calculate_mu_manual(
    mass: float, semi_minor_axis: float, ecc_squared: float
) -> float:
    mu = mass / integrate_quad(
        lambda theta: semi_minor_axis
        / np.sqrt(1 - ecc_squared**2 * np.cos(theta) ** 2),
        0,
        2 * np.pi,
    )
    print(f"Manual: Mu = {mu}")
    return mu


def integrate_quad(func, a: float, b: float) -> float:
    eps = 1.49e-8
    interval_stack = [(a, b)]
    result = 0
    while interval_stack:
        left, right = interval_stack.pop()
        gauss_approx = calculate_gauss_quadrature(func, left, right)
        kronrod_approx = calculate_kronrod_quadrature(func, left, right)
        if abs(gauss_approx - kronrod_approx) < eps:
            result += kronrod_approx
        else:
            mid = (left + right) / 2
            interval_stack.append((left, mid))
            interval_stack.append((mid, right))

    return result


def main():
    mass = 1
    semi_minor_axis = 1
    semi_major_axis = 2
    ecc_squared = 1 - (semi_minor_axis / semi_major_axis) ** 2
    mu_scipy = calculate_mu_scipy(mass, semi_minor_axis, ecc_squared)
    mu_manual = calculate_mu_manual(mass, semi_minor_axis, ecc_squared)


if __name__ == "__main__":
    main()
