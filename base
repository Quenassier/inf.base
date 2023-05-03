#include <iostream>
#include <string>
#include <vector>

class Category {
public:
    int id;
    std::string name;
};

class Brand {
public:
    int id;
    std::string name;
};

class Seller {
public:
    int id;
    std::string name;
};

class Product {
public:
    int id;
    Seller seller;
    Brand brand;
    Category category;
    std::string name;
};

std::string convert(std::string res) {
    int size = res.size();

    if (size < 20) {
        for (; res.size() < 20;) {
            res += ' ';
        }
    }
    return res;
}

int main() {
    setlocale(LC_ALL, "Russian");
    std::vector<Category> categories;
    std::vector<Brand> brands;
    std::vector<Seller> sellers;
    std::vector<Product> products;


    Category category1{ 1, "электроника " };
    Category category2{ 2, "одежда" };
    Category category3{ 3, "дом и сад" };
    Category category4{ 4, "спорт" };
    Category category5{ 5, "уход за собой" };

    categories.push_back(category1);
    categories.push_back(category2);
    categories.push_back(category3);
    categories.push_back(category4);
    categories.push_back(category5);

    Brand brand1{ 1, "Nike" };
    Brand brand2{ 2, "Apple" };
    Brand brand3{ 3, "Samsung" };
    Brand brand4{ 4, "Adidas" };
    Brand brand5{ 5, "LG" };

    brands.push_back(brand1);
    brands.push_back(brand2);
    brands.push_back(brand3);
    brands.push_back(brand4);
    brands.push_back(brand5);

    Seller seller1{ 1, "Amazon" };
    Seller seller2{ 2, "Best Buy" };
    Seller seller3{ 3, "Walmart" };
    Seller seller4{ 4, "Target" };
    Seller seller5{ 5, "Costco" };

    sellers.push_back(seller1);
    sellers.push_back(seller2);
    sellers.push_back(seller3);
    sellers.push_back(seller4);
    sellers.push_back(seller5);

    Product product1{ 1, seller1, brand1, category4, "беговая обувь" };
    Product product2{ 2, seller2, brand2, category1, "iPhone" };
    Product product3{ 3, seller3, brand3, category3, "холодильник" };
    Product product4{ 4, seller4, brand4, category2, "майка" };
    Product product5{ 5, seller5, brand5, category5, "шампунь" };

    products.push_back(product1);
    products.push_back(product2);
    products.push_back(product3);
    products.push_back(product4);
    products.push_back(product5);


    std::cout << convert("id")<< convert("Имя")<< convert("Продавец")<< convert("Бренд")<< convert("Категория") << "\n";
    for (auto category : categories) {
        std::cout << "Категория: " << category.name << std::endl;
        for (auto product : products) {
            if (product.category.id == category.id) {
                std::cout << convert(std::to_string( product.id)) << convert( product.name)<<convert( product.seller.name)<<convert(product.brand.name)
                    << convert(product.category.name) << '\n';
            }
        }
    }
    return 0;
}
